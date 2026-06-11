// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
const ll MAX = 310;
const ll INF = 1e15;
signed main(){
  init_io();
  ll n,K;
  cin >> n >> K;
  vector<ll> h(n+1);
  h[0] = 0;
  for(int i=0;i<n;i++){
    cin >> h[i+1];
  }
  vector<vector<ll>> dp(MAX,vector<ll>(MAX,INF));
  dp[0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      ll v = INF;
      for(int k=0;k<i;k++){
        v = min(v,dp[k][j-1]+max(0ll,h[i]-h[k]));
      }
      dp[i][j] = v;
    }
  }
  ll ans = INF;
  for(int i=0;i<=n;i++){
    ans = min(ans,dp[i][n-K]);
    /*
    for(int j=0;j<=n;j++){
      cout << dp[i][j] <<" ";
    }
    cout << endl;
    */
  }
  cout << ans<<endl;
}
