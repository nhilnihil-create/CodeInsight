#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

ll modpow(ll a,ll n){
    if(n==0) return 1;
    else if(n==1) return a;
    else if(n%2) return a*modpow(a*a%mod,(n-1)/2)%mod;
    else return modpow(a*a%mod,n/2);
}

ll modfact(ll na,ll nz){
    if(na==nz) return 1;
    else return na*modfact(na-1,nz)%mod;
}

ll modcomb(ll n,ll k){
    return modfact(n,k)*modpow(modfact(n-k,0),mod-2)%mod;
}

int main(){
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=k;i++){
        if(i>n-k+1) cout<<0<<endl;
        else cout<<modcomb(n-k+1,i)*modcomb(k-1,i-1)%mod<<endl;
    }
    return 0;
}