#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,t;
  cin >> n >> t;
  vector<P> v(n);
  rep(i,n)cin >> v[i].first >> v[i].second;
  sort(ALL(v));
  vector<vector<int>> dp(3010,vector<int>(3010,-1e7));
  dp[0][0] = 0;
  rep(i,n)rep(j,t+1){
    dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
    if(j == t || dp[i][j] < 0)continue;
    dp[i+1][min(t*1ll,j+v[i].first)] = max(dp[i+1][min(t*1ll,j+v[i].first)],dp[i][j]+v[i].second);
  }
  int res = 0;
  rep(i,3010)res = max(res,dp[n][i]);
  cout << res << endl;




  return 0;
}