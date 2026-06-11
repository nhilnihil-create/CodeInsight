#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int64> hs(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> hs[i];
  }

  auto dp = Make2DVector<int64>(n + 1, n + 1, INT64_MAX);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int l = 0; l < i; l++) {
      for (int k = 0; k < i; k++) {
        if (dp[l][k] < INT64_MAX) {
          UpdateMin(dp[i][k + 1], dp[l][k] + max(hs[i] - hs[l], 0LL));
        }
      }
    }
  }

  int64 ans = INT64_MAX;
  for (int l = 0; l <= n; l++) {
    UpdateMin(ans, dp[l][n - m]);
  }
  cout << ans << endl;
}