#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#define mod 1000000007
using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    a=abs(a);
    long long k=a/c;
    if(k>=b)
    {
        printf("%lld\n",a-(b*c));
    }
    else
    {
        long long x = b-k;
        long long n = a%c;
        long long m = c-n;
        if(x%2==0)
        {
            printf("%lld\n",n);
        }
        else
            printf("%lld\n",m);

       // printf("%lld\n",min(n,m));
        //printf("%lld\n",min(n,long long(abs(n-c))));
    }
    return 0;
}
