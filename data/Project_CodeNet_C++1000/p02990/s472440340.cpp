#include<iostream>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int MAX=10000;

ll fac[MAX],inv[MAX],finv[MAX];
void COMinit(){
    fac[0]=fac[1]=1;
    inv[1]=1;
    finv[0]=finv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i % mod;
        inv[i]=mod-inv[mod%i]*(mod/i) % mod;
        finv[i]=finv[i-1]*inv[i] % mod;
    }
}

ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main(){
    COMinit();
    ll n,k;cin>>n>>k;
    for(int i=1;i<=k;i++){
        ll ans=COM(n-k+1,i)*COM(k-1,i-1)%mod;
        cout<<ans<<endl;
    }
    return 0;
}