#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
const ll mod=1e9+7;
vector<ll>cnt((ll)1e6+5);
int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n);
    rep(0,i,n)cin>>a[i];
    cnt[0]=3;
    ll ans=1;
    rep(0,i,n){
        if(cnt[a[i]]>0){
            ans*=cnt[a[i]];
            ans%=mod;
            --cnt[a[i]];
            ++cnt[a[i]+1];
        }else{
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<ans;
}