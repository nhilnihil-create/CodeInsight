#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

const int mod=1e9+7;
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int main(){
    int n;cin>>n;
    ll ans=(modpow(10,n)-(modpow(9,n)*2)%mod+modpow(8,n))%mod;
    cout<<(ans+mod)%mod<<endl;
}