#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n, t; cin >> n >> t;
  vector<pair<int, int>> p(n + 1);
  vector<vector<int>> dp(n+1, vector<int>(t+1));
  rep(i, n) cin >> p[i + 1].first >> p[i + 1].second;
  sort(p.begin() + 1, p.end());
  rep(i, t + 1) dp[0][i] = 0;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= t; j++){
      if(j - p[i].first < 0) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i].first] + p[i].second);
    }
    ans = max(ans, dp[i - 1][t - 1] + p[i].second);
  }

  /*for(int i = 0; i <= n; i++){
    for(int j = 0; j <= t; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */
  cout << ans << endl;
  return 0;
}
