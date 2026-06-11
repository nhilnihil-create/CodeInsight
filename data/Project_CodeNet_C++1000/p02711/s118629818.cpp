#include<stdio.h>
int main()
{
    int n,i=0,r;
    scanf("%d", &n);
    while(n>0)
    {
        r=n%10;
        if(r==7)
        {
            i=1
            ;break;
        }
        n=n/10    ;
    }
    if(i==1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
