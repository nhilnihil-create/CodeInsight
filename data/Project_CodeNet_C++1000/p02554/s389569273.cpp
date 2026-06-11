#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(ll b, ll p)
{
    ll i, ans = 1;
    for(i=1;i<=p;i++){
        ans *= b;
        ans %= mod;
    }
    return ans;
}

int main()
{
    ll n,ans;
    scanf("%lld", &n);
    ans = (((func(10,n)-(2*func(9,n))+func(8,n))%mod)+mod)%mod;
    printf("%lld\n", ans);
    return 0;
}