#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> S(N), T(M);
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < M; i++) cin >> T[i];

  vector<vector<ll>> dp(N, vector<ll>(M)), sum(N, vector<ll>(M));
  dp[0][0] = sum[0][0] = (S[0] == T[0]);
  for (int i = 1; i < N; i++) {
    dp[i][0] = (S[i] == T[0]);
    sum[i][0] = sum[i - 1][0] + dp[i][0];
  }
  for (int j = 1; j < M; j++) {
    dp[0][j] = (S[0] == T[j]);
    sum[0][j] = sum[0][j - 1] + dp[0][j];
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < M; j++) {
      dp[i][j] = S[i] == T[j] ? sum[i - 1][j - 1] + 1 : 0;
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + dp[i][j];
      sum[i][j] = (sum[i][j] + MOD) % MOD;
    }
  }
  cout << (sum[N - 1][M - 1] + 1) % MOD << endl;
}