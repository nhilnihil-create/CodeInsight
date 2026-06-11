#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int nmax=200005;
ll fact[nmax],finv[nmax],inv[nmax];
 
void inicom(){
    fact[0]=fact[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i = 2; i < nmax; i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll pow(ll n,ll k,ll m){
    ll res=1;
    for(;k>0;k>>=1){
        if(k&1){
            res=(res*n)%m;
        }
        n=(n*n)%m;
    }
    return res;
}

int main(){
    ll n,a,b; cin>>n>>a>>b;
    if(n==2){
        cout<<0<<endl;
        return 0;
    }
    ll ans=(pow(2,n,mod)-1+mod)%mod;
    inicom();
    ll p=finv[a],q=finv[b];//p=(a!)^(-1),q=(b!)^(-1)
    for (int i = 0; i < a; i++){
        p*=(n-i);
        p%=mod;
    }
     for (int i = 0; i < b; i++){
        q*=(n-i);
        q%=mod;
    }
    ans=(ans-p+mod-q+mod)%mod;
    cout<<ans<<endl;
   
}