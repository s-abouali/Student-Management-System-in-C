#include <stdio.h>
#include <string.h>

#define MAX 3

struct Student {
    int id;
    char name[50];
    float marks[3];
    float average;
};

void calculateAverage(struct Student *s) {
    s->average = (s->marks[0] + s->marks[1] + s->marks[2]) / 3.0;
}

// Function to display student details
void displayStudent(struct Student s) {
    printf("\nID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f %.2f %.2f\n",
           s.marks[0], s.marks[1], s.marks[2]);
    printf("Average: %.2f\n", s.average);
}

int main() {
    struct Student students[MAX];
    struct Student temp;
    int i, j;

    for(i = 0; i < MAX; i++) {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        getchar(); 

        printf("Enter Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        for(j = 0; j < 3; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }

        calculateAverage(&students[i]);
    }
    for(i = 0; i < MAX - 1; i++) {
        for(j = i + 1; j < MAX; j++) {
            if(students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\n===== Student Ranking =====\n");

    for(i = 0; i < MAX; i++) {
        displayStudent(students[i]);
    }

    return 0;
}