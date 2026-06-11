#include <iostream>
#include <vector>

#define MAX_N 300

using namespace std;

typedef long long ll;

int N, K;
vector<ll> H;

ll solve() {
  vector<vector<ll>> dp(N, vector<ll>(N + 1, 1e11));

  if (N == K) {
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    dp[i][1] = H[i];
  }

  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      for (int k = 0; k < i; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0ll, H[i] - H[k]));
      }
    }
  }

  ll result = 1e11;

  for (int i = 0; i < N; ++i) {
    result = min(result, dp[i][N - K]);
  }

  return result;
}

int main() {
  cin >> N >> K;

  H = vector<ll>(N);

  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }

  cout << solve() << endl;

  return 0;
}