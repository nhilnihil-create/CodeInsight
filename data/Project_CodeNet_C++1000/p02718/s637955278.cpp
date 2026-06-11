#include<iostream>

using namespace std;

int A[1010];

int partation (int l, int r) {
    
    int temp;
    int i = l-1;
    int x = A[r];
    for (int j = l; j < r; j++) {
        if (A[j] >= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i+1;
}

int quickSort (int l, int r) {

    int m;
    if (l < r) {
        m = partation(l, r);
        quickSort(l, m-1);
        quickSort(m+1, r);
    }

    return 0;
}

int main () {

    int n, m;
    int sum = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sum+=A[i];
    }

    quickSort(0, n-1);


    if (double(A[m-1]) >= ((double(sum)/double(4*m)))) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}