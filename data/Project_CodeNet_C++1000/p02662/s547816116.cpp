#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

int main() {
  int N, S;
  cin >> N >> S;

  vector<long long> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  vector<vector<long long>> dp(N + 10, vector<long long>(S + 10, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] += dp[i - 1][j] * 2;
      dp[i][j] %= mod;
      if (j + A[i] <= S) {
        dp[i][j + A[i]] += dp[i - 1][j];
        dp[i][j + A[i]] %= mod;
      }
    }
  }
  cout << dp[N][S] << "\n";

  return 0;
}