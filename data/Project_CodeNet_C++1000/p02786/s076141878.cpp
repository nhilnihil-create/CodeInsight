#include <stdio.h>

typedef long long int llint;

llint h;
llint ans=0;
llint n=1;

int main()
{
    scanf("%lld",&h);
    while(h>0)
    {
        h>>=1;
        ans+=n;
        n<<=1;
    }
    printf("%lld\n",ans);
}