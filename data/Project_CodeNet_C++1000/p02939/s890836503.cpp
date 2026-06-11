#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  vector<vector<int>> dp(n + 1,vector<int>(2));
  dp[1][0] = 1;
  for (int i = 2; i <= n; ++i) {
    if (S[i-1] != S[i-2]) dp[i][0] = dp[i-1][0] + 1;
    if (i < 4 || S[i-1] != S[i-3] || S[i-2] != S[i-4])
      dp[i][1] = dp[i-2][1] + 1;
    if (i > 2) dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
    if (i > 2) dp[i][1] = max(dp[i][1], dp[i-2][0] + 1);
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
}
