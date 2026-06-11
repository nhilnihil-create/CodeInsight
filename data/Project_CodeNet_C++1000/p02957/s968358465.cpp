#include<stdio.h>
#include<stdbool.h>

int main()
{
    int A,B,d1,d2,K,max;
    scanf("%d %d",&A,&B);
    _Bool hobe = 0;
    max = A<B?B:A;
    for(int i=0;i<=max;i++)
    {
        d1 = A-i;
        if(d1<0)
        {
            d1*=(-1);
        }
        d2 = B-i;
        if(d2<0)
        {
            d2*=(-1);
        }
        if(d1==d2)
        {
            K = i;
            hobe = 1;
            break;
        }
    }
    if(hobe==1)
    {
        printf("%d",K);
    }
    else
    {
        printf("IMPOSSIBLE");
    }

}
