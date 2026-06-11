#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll mod=1e9+7;
int main(void){
    ll s;
    cin>>s;
    ll f[s+1];
    rep(0,i,s+1)f[i]=0;
    f[0]=1;
    rep(0,i,s+1){
        rep(3,j,s+1)if(i+j<s+1)f[i+j]=(f[i]+f[i+j])%mod;
    }
    cout<<f[s];
}
