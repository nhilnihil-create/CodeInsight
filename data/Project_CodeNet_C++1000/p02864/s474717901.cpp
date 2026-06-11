#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    cout << v[i] << " \n"[i == sz - 1];
  }
}

constexpr int MAX_N = 310, MAX_K = 310;
ll dp[MAX_N][MAX_K][MAX_N];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= N; k++) {
        dp[i][j][k] = 1e15;
      }
    }
  }
  vector<ll> h(N + 1);
  for (int i = 1; i <= N; i++) cin >> h[i];
  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= i; k++) {
        dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k]);
        dp[i + 1][j][i + 1] =
            min(dp[i + 1][j][i + 1], dp[i][j][k] + max(h[i + 1] - h[k], 0LL));
      }
    }
  }
  ll ret = 1e15;
  for (int j = 0; j <= K; j++) {
    for (int k = 0; k <= N; k++) {
      ret = min(ret, dp[N][j][k]);
    }
  }
  cout << ret << endl;
}
