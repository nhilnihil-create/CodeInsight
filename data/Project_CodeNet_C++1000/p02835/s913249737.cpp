#include <stdio.h>

int main()
{
    int A[3];
    scanf("%d %d %d", &A[0], &A[1], &A[2]);
    int sum = A[0] + A[1] + A[2];
    
    if (sum >= 22) 
    {
        printf("bust");
    } else 
    {
        printf("win");
    }

    return 0;
}