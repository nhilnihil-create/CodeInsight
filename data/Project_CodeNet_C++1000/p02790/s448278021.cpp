#include<stdio.h>
int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    if(a==b)
    {
        int ar[10];

        for(int i=0; i<a; i++)
        {
            ar[i]=a;
        }

        for(int i=0; i<b; i++)
        {
            printf("%d", ar[i]);
        }

        printf("\n");
    }

    else
    {
        if(a>b)
        {
            for(int i=0; i<a; i++)
            {
                printf("%d", b);
            }
        }

        else if(b>a)
        {
            for(int i=0; i<b; i++)
            {
                printf("%d", a);
            }
        }

        printf("\n");
    }

    return 0;
}