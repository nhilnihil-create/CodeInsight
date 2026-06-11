#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

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
      dp[i][j] += dp[i - 1][j];
      dp[i][j] %= mod;
      if (j - A[i] >= 0) {
        dp[i][j] += dp[i - 1][j - A[i]] * (mod + 1) / 2;
        dp[i][j] %= mod;
      }
    }
  }

  cout << (dp[N][S] * mod_pow(2, N, mod)) % mod << "\n";

  return 0;
}