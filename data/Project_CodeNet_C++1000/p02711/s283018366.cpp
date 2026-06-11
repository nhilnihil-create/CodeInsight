#include<stdio.h>
int main()
{
    int n,i,d=0;
    scanf("%d",&n);
    while(n!=0)
    {
        i=n%10;
        if(i==7){printf("Yes");d=1;break;}
        n/=10;
    }
    if(d!=1)printf("No");
    return 0;
}
