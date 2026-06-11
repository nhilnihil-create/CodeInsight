#include<stdio.h>

int main()
{
    int A, B;
    double x, y;
    scanf("%d %d", &A, &B);
    y = ((double)A+(double)B)/2;
    x = y - (int)y;

    if(x == 0)printf("%d", (int)y);
    else printf("IMPOSSIBLE");

}