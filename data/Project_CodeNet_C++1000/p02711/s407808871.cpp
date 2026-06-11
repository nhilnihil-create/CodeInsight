#include<stdio.h>

int main()
{
    int n, count=0;

    scanf("%d", &n);

    while(n != 0)
    {
        if(n % 10 == 7)
        {
            count++;
            break;
        }
        n = n/10;
    }

    if(count == 1)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
