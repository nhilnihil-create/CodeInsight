#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll h,n;
    cin>>h>>n;
    vector<pair<ll,ll>>p(n);
    rep(0,i,n){
        cin>>p[i].first>>p[i].second;
    }
    ll dp[h+1];
    rep(0,i,h+1)dp[i]=(ll)1e9;
    dp[0]=0;
    rep(0,i,h){
        rep(0,j,n){
            ll a=p[j].first,b=p[j].second,x=min(i+a,(ll)h);
            dp[x]=min(dp[x],dp[i]+b);
        }
    }
    cout<<dp[h]<<endl;
}
