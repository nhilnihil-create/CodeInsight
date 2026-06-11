#include <stdio.h>

int main()
{
    int K,X,sum;
    scanf("%d %d", &K,&X);
    
    sum = K*500;

    if (sum >= X) {
        printf("Yes");
    }
    else {
        printf("No");
    }
}