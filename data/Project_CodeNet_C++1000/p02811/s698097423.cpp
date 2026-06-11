#include <stdio.h>

int main()
{
    int num, max;
    scanf("%d %d", &num, &max);

    num *= 500;
    num >= max ? printf("Yes\n") : printf("No\n"); 

    return 0;
}