#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


const ll INF = 1e18;

int main() {
  ll n, t;
  cin >> n >> t;
  vector<P> v(n);
  rep(i,n){
    ll a1,b1;
    cin>>a1>>b1;
    v[i]=make_pair(a1,b1);
  }
  sort(v.begin(),v.end());
  ll dp[n+5][t+3000];
  dp[0][0]=0;
  ll ans=0;

  rep(i,n){
    rep(j,t){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      dp[i+1][j+v[i].first]=max(dp[i+1][j+v[i].first],dp[i][j]+v[i].second);
    }
    ans=max(ans,dp[i][t-1]+v[i].second);
  }
cout<<ans;

}
