#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  
  vector<vector<int>> dp(s.size(), vector<int>(2, 0));
  dp[0][0] = 1;
  dp[1][1] = 1;
  if (s[0] != s[1]) dp[1][0] = 2;
  for (int i = 2; i < s.size(); ++i) {
    dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
    dp[i][1] = max(dp[i][1], dp[i-2][0] + 1);
    if (s[i-1] != s[i]) dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
    if (i > 3) if (s[i-3] != s[i-1] || s[i-2] != s[i]) dp[i][1] = max(dp[i][1], dp[i-2][1] + 1);
  }
  int ans = max(dp[s.size()-1][0], dp[s.size()-1][1]);
  cout << ans << endl;
  return 0;
}