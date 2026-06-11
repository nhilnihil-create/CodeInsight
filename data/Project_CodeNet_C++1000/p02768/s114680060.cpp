#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mx 1000000000
#define ll long long


ll bigMod(ll n,ll p){
    if(p==0) return 1;
    if(p%2==0){
       ll ret=bigMod(n,p/2);
       return ((ret%mod)*(ret%mod))%mod;
    }
    else return ((n%mod)*(bigMod(n,p-1)%mod))%mod;
}

ll modInverse(ll n){
   return bigMod(n,mod-2);
}

ll nCr(ll n,ll r){
    if(r>n) return 0;
    ll ans=1;

    for(int i=1;i<=r;i++) (ans=ans*(n-i+1)%mod*modInverse(i)%mod)%mod;
    return ans;
}

int main(){
    ll n,a,b;
    ll c1,c2,c;
    scanf("%lld %lld %lld",&n,&a,&b);


    c=bigMod(2,n)-nCr(n,a)-nCr(n,b)-1;
    c=(c%mod+mod)%mod;
    printf("%lld\n",c);

return 0;
}
