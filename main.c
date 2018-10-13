/*
 * This program reads the amount of values the user chooses.
 * Then prints which of this numbers are unique.
 *
 * Email: A01411277@itesm.mx
 * Author: Jonathan Nuñez de Caceres
 * Date: 12/10/18
 */

#include <stdio.h>
#include <stdlib.h>

// Compare function for the sorting function
int Compare(const void * a, const void * b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    // Declaration of variables.
    int n;
    int k = 0;
    int count = 0;
    int uqcount = 0;

    printf("How many values you want to enter?");
    scanf("%d", &n);

    // Declaration of arrays.
    int numbers[n];
    int unique[n];

    // Initializing of each element with NULL.
    for(int i = 0; i < n; i++){
        unique[i] = '\0';
    }

    // Storing of the values.
    for(int i = 0; i < n; i++){
        printf("%d:", i+1);
        scanf("%d", &numbers[i]);
    }

    // Sorting function.
    qsort(numbers, n, sizeof(int), Compare);

    // After sorting we count for every number how many are there.
    // If there is more than one of the same number, count increments and
    // we skip in the first for all those numbers.
    for(int i = 0; i < n; i+=count+1){
        count = 0;
        for(int j = i + 1; j < n; j++){
            if(numbers[i] == numbers[j]){
                count++;
            }
        }
        // If the value is unique it is stored in the "unique" array.
        if(count == 0){
            unique[k] = numbers[i];
            k++;
        }
    }

    // Prints the unique array.
    printf("The unique numbers are: ");
    for(int i = 0; i < n; i++){
        // If all the values in the array are already printed,
        // and there is empty elemets, we break out of the loop.
        if(unique[i] == '\0'){
            break;
        }
        printf("%d ", unique[i]);
        uqcount++;
    }

    // If there was not any unique element, the program prints that
    // there were none.
    if(uqcount == 0){
        printf("none.");
    }

    return 0;
}
