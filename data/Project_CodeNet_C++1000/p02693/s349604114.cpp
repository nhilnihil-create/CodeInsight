#include <stdio.h>

int main ()
{
    int m,n,x,s;
    scanf("%d", &m);
    scanf("%d %d", &n, &x);
        for (n;n<=x;n++)
        {
            if(n%m==0)
            {
            s++;
            }
        }
    if(s!=0)
    {
        printf("OK");
    }
    else
    {
        printf("NG");
    }


    return 0;
}