/////jdjs
#include<stdio.h>
int main()
{
    long long a,b,c,d;
    scanf("%lld %lld %lld",&a,&b,&c);
    if(c<=a)
    {
        printf("%lld %lld",a-c,b);
    }
    else if(c>a)
        {
        d=c-a;
        if(d<=b) printf("0 %lld",b-d);
        else printf("0 0");
    }
        
        
        
        
    
    
    return 0;
}