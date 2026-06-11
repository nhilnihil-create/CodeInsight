#include <iostream>

typedef long long ll;
const ll MOD = 998244353;

ll N, S, A[3005], dp[3005][3005];

ll fast_exp(ll b, ll e) {
  ll res = 1;
  while (e) {
    if (e & 1)  res = (res * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return res % MOD;
}

ll solve(int i, int s) {
  if (s == 0) return fast_exp(2, i+1);
  if (i == -1)  return 0;
  if (dp[i][s] != -1) return dp[i][s];
  int ans = (2*solve(i-1, s)) % MOD;
  if (A[i] <= s)
    ans = (ans + solve(i-1, s - A[i])) % MOD;
  return dp[i][s] = ans;
}

int main() {
  std::cin >> N >> S;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    for (int j = 0; j <= S; ++j)
      dp[i][j] = -1;
  }

  std::cout << solve(N-1, S) << "\n";

  return 0;
}
