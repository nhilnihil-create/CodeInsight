#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll n;
    cin>>n;
    ll ans=0,c=0;
    vector<ll>h(n);
    rep(0,i,n){
        cin>>h[i];
        if(i!=0&&h[i-1]>=h[i])++c;
        else c=0;
        ans=max(c,ans);
    }
    cout<<ans;
}
