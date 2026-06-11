#include <stdio.h>
 
int main()
{
    int a = 0, b= 0;

    scanf("%d", &a);
    scanf("%d", &b);

    if(a==b)
    {
        printf("a == b\n");
        return 0;
    }
    else if(a < b)
    {
        printf("a < b\n");
        return 0;
    }
    else
    {
        printf("a > b\n");
        return 0;
    }

    return 0;
}