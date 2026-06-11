#include<stdio.h>
#include<iostream>

#define MAX 100000

int partition(int* A, int p, int r)
{
    int i, j, x;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
		if(A[j] <= x){ i++; std::swap(A[i], A[j]); }
    }
	std::swap(A[i + 1], A[r]);

    return i + 1;
}

int main()
{
    int i, n, A[MAX], q;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    q = partition(A, 0, n - 1);

    for(i = 0; i < q; i++){ printf("%d ", A[i]); }

    printf("[%d]", A[q]);

    for(i = q + 1; i < n; i++){ printf(" %d", A[i]); }

    printf("\n");

    return 0;
}