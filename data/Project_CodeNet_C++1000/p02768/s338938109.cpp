#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
#define ll long long
const int mod=1e9+7;
ll n, a, b;

ll q_pow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

ll C(ll a, ll b){
    ll ans=1, c=1, i;
    for (i=a; i>=a-b+1; i--) ans=ans*i%mod;
    for (i=b; i>=1; i--) c=c*i%mod;
    return ans*q_pow(c, mod-2)%mod;
}

int main(){
    ll ans=0;
    scanf("%lld%lld%lld", &n, &a, &b);
    ans+=q_pow(2,n)-1;
    ans-=C(n, a);
    ans-=C(n, b);
    ans=(ans%mod+mod)%mod;
    printf("%lld\n", ans);
}
