#include <stdio.h>

int main()
{
    int A1, A2, A3, sum;
    scanf("%d %d %d", &A1, &A2, &A3);

    sum = A1 + A2 + A3;
    
    if (sum >= 22) {
        printf("bust");
    }
    else {
        printf("win");
    }
    return 0;
}