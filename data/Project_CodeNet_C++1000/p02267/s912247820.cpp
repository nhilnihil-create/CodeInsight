#include<stdio.h>


bool lineSearch(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int A[10000];
    int n, q, key;
    int count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        scanf("%d", &key);
        if (lineSearch(A, n, key))  count++;
    }
    
    printf("%d\n", count);
}