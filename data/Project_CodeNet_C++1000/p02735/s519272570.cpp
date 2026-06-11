#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> s(H, vector<int>(W)), dp(H, vector<int>(W));
  rep(i, H) rep(j, W) {
    char c; cin >> c;
    s[i][j] = (c == '#' ? 1 : 0);
  }
  
  rep(i, H) rep(j, W) {
    if(i==0 && j==0) {
      dp[i][j] = 0;
      continue;
    }
    dp[i][j] = 1000000;
    if(i > 0) {
      int l = dp[i-1][j];
      if(s[i-1][j] != s[i][j]) l++;
      dp[i][j] = min(dp[i][j], l);
    } 
    if(j > 0) {
      int u = dp[i][j-1];
      if(s[i][j-1] != s[i][j]) u++;
      dp[i][j] = min(dp[i][j], u);
    }
  }
  if(s[0][0]==1 && s[H-1][W-1]==1) dp[H-1][W-1]++;
  cout << (dp[H-1][W-1]+1)/2 << endl;

}