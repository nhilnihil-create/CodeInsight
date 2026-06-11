#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll func(ll n)
{
    ll x= 5ll, ret= 0;
    while(x<=n)ret+= (n/x), x*= 5ll;
    return ret;
}
int main()
{
    ll n;
    scanf("%lld", &n);
    if(n&1ll)printf("0\n");
    else printf("%lld\n", func(n/2ll));
    return 0;
}
