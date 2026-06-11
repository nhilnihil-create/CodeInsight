#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 1000000000

int A[MAX];
std::vector<int> g;
int cnt = 0;

void insertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while ( j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt ++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int n) {
    for (int h = 1; ; ) {
        if ( h > n ) break;
        g.push_back(h);
        h = 3 * h + 1;
    }
    
    for ( int i = g.size()-1; i >= 0; i-- ) {
        insertionSort(A, n, g[i]);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++ ) scanf("%d", &A[i]);
    
    shellSort(A, n);
    
    printf("%d\n", g.size());
    for (int i = g.size()-1; i >= 0; i--) {
        printf("%d", g[i]);
        if(i) printf(" ");
    }
    printf("\n");
    printf("%d\n", cnt);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
    
    
    return 0;
}