#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,d,p1,p2,p3,p4,maximum;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    maximum=max(max(a*c,a*d),max(b*c,b*d));
    printf("%lld",maximum);
    return 0;
}