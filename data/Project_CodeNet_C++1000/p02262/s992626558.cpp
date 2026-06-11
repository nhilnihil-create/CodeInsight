#include <stdio.h>
long long cnt;
int G[100];
int m;

void insertionSort(int A[], int n, int g) {
    int v, i, j;

    for (i=g; i<n; i++) {
        v = A[i];
        j = i-g;
        while (j>=0 && A[j]>v) {
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g]=v;
    }
}

void print(int m, int G[], int A[], int n) {
    printf("%d", m);
    printf("\n");
    for (int i=0; i<m; i++) {
        if (i>0) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n");
    printf("%d", cnt);
    printf("\n");
    for (int i=0; i<n; i++) {
        printf("%d", A[i]);
        printf("\n");
    }
}

void shellSort(int A[], int n) {
    int i;
    int g=0;
    m = -1;
    
    while (m<100 && g<=n) {
        g = 3*g+1;
        m++;
    }
    g = 0;
    for (i=m-1; i>=0; i--) {
        g = 3*g+1;
        G[i] = g;
    }

    for (i=0; i<m; i++) insertionSort(A, n, G[i]);
}

int main() {
    int A[1000000], n;
    cnt = 0;

    scanf("%d", &n);

    for (int i=0; i<n; i++) scanf("%d", &A[i]);

    shellSort(A, n);

    print(m, G, A, n);

    return 0;
}
