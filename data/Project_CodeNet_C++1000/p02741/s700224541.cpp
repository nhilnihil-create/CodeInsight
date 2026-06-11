#include <stdio.h> 
int main()
{
    int c[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int b;
    scanf("%d",&b);
    printf("%d",c[b-1]);
    return 0;
}