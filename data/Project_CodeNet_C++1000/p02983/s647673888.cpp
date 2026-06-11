#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll mod=2019;
int main(void){
    // Your code here!
    ll l,r;
    cin>>l>>r;
    if(r-l>2019){
        cout<<0<<endl;
        return 0;
    }
    ll ans=3000;
    rep(l,i,r+1){
        rep(i+1,j,r+1)ans=min(i*j%mod,ans);
    }
    cout<<ans;
}
