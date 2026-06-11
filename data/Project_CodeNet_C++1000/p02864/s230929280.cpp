#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


const ll INF = 1e18;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n+1);
  h[0]=0;
  rep(i,n){
    cin>>h[i+1];
  }
  ll dp[305][305];
  rep(i,305)rep(j,305)dp[i][j]=INF;
  dp[0][0]=0;
  rep(i,n)rep(j,n-k){
    rep(k,i+1){
      dp[i+1][j+1]=min(dp[i+1][j+1],dp[k][j]+max(ll(0),h[i+1]-h[k]));
  //    dp[i+1][j]=min(dp[i+1][j],dp[k][j-1]+abs(h[i+1]-h[k]));
    //  cout<<i+1<<"i"<<j+1<<'j'<<k<<'k'<<"dp"<<dp[i+1][j+1]<<"abs"<<abs(h[i+1]-h[k])<<endl;
    }
  }
  ll ans=INF;
  rep(i,n+1){
    ans=min(ans,dp[i][n-k]);
  }
  cout<<ans;

}
