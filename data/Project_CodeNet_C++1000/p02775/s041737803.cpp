#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  int len = S.length();
  vector<int> N(len);
  for (int i = 0; i < len; i++) N[i] = S[i] - '0';
  vector<vector<long long>> dp(len + 5, vector<long long>(2));
  dp[0][0] = 0;
  dp[0][1] = 1;
  for (int i = 0; i < len; i++) {
    dp[i + 1][0] = min(dp[i][0] + N[i], dp[i][1] + (10 - N[i]));
    dp[i + 1][1] = min(dp[i][0] + N[i] + 1, dp[i][1] + (10 - N[i] - 1));
  }
  cout << dp[len][0] << endl;

  return 0;
}
/* vim:set fdm=marker: */
