#include<stdio.h>

int cnt;

void insertionSort(int* a, int n, int g){

    int i, j, v;

    for(i = g; i < n; i++){
        v = a[i];
        j = i - g;
        while((j >= 0) && (a[j] > v)){
            a[j + g] = a[j];
            j = j - g;
            cnt++;
        };
        a[j + g] = v;
    }
}

void shellsort(int* a, int n)
{
    cnt = 0;
    int i, p;
    int m;
    int G[15];

    p = 1;
    for(i = 1; i < 20; i++){
        p = p * 3;
        if(p - 1 > 2 * n) break;
    }
    if(i > 1) i = i - 1;
    m = i;

    p = 1;
    for(i = 0; i < m; i++){
        p = p * 3;
        G[m - 1 - i] = (p - 1) / 2;
    }
    printf("%d\n", m);
    for(i = 0; i < m - 1; i++) printf("%d ", G[i]);
    printf("%d\n", G[m - 1]);

    for(int i = 0; i < m; i++){
        insertionSort(a, n, G[i]);
    }
}

int main()
{
    int i, A[1000000], n;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    shellsort(A, n);
    printf("%d\n", cnt);
    for(i = 0; i < n; i++) printf("%d\n", A[i]);

    return 0;
}