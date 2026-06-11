#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
ll dp[2001][2001];
int main(void){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>p(n);
    rep(0,i,n){
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p.rbegin(),p.rend());
    rep(0,i,n+1)rep(0,j,n+1)dp[i][j]=0;
    rep(0,i,n){
        ll k=p[i].first;
        ll r=p[i].second;
        rep(0,x,i+1){
            ll y=i-x;
            dp[x+1][y]=max(dp[x+1][y],dp[x][y]+k*abs(r-x));
            dp[x][y+1]=max(dp[x][y+1],dp[x][y]+k*abs(n-1-y-r));
        }
    }
    ll ans=0;
    rep(0,i,n)ans=max(dp[i][n-i],ans);
    cout<<ans;
}
