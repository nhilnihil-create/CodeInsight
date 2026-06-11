#include <bits/stdc++.h>
#define INF ((int)1e9)
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<vector<int>> dp(s.length() + 1, vector<int>(2));
  dp[0][1] = 1;
  for(int i = 0; i < s.length(); i++) {
    int d = s[i] - '0';
    dp[i + 1][0] = min(dp[i][0] + d, dp[i][1] + 10 - d);
    dp[i + 1][1] = min(dp[i][0] + d + 1, dp[i][1] + 9 - d);
  }
  cout << dp[s.length()][0] << '\n';
}