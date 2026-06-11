#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,d,x,y;
    scanf("%lld %lld %lld %lld", &a,&b,&c,&d);
    x = max(max(a*c,a*d), max(b*c,b*d));
    printf("%lld\n", x);
    return 0;
}