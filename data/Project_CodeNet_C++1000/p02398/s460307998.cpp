#include<stdio.h>
int main()
{
    int a,b,c,i,div;
    scanf("%d%d%d",&a,&b,&c);
    for(i=a;b>=i;i++)
    {
        if(c%i==0)
        {
            div++;
        }
    }
    printf("%d\n",div);
    return 0;
}