#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
static ll f[(ll)1e7+5]={0};
int main(void){
    ll n;
    cin>>n;
    rep(1,i,n+1){
        for(ll j=i;j<=n;j+=i)++f[j];
    }
    //rep(0,i,n+1)cout<<f[i]<<endl;
    ll ans=0;
    rep(1,i,n+1)ans+=i*f[i];
    cout<<ans;
}
