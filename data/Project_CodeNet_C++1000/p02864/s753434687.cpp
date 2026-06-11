#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  const long long INF = LLONG_MAX / 10;
  int N, K;
  cin >> N >> K;
  long long H[N + 1];
  H[0] = 0;
  for (int i = 1; i <= N; i++) cin >> H[i];
  vector<int> vec(H, H + N + 1);
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  auto id = [&](int x) {
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  for (int i = 0; i <= N; i++) H[i] = id(H[i]);
  debugArray(H, N + 1);
  long long dp[N + 1][N + 1][K + 1];
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++) fill(dp[i][j], dp[i][j] + K + 1, INF);
  fill(dp[0][0], dp[0][0] + K + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= K; k++) {
        dp[i][H[i]][k]
            = min(dp[i][H[i]][k], dp[i - 1][j][k] + max(0, vec[H[i]] - vec[j]));
        if (k < K) dp[i][j][k + 1] = min(dp[i][j][k + 1], dp[i - 1][j][k]);
      }
    }
  }
  long long ans = INF;
  for (int j = 0; j <= N; j++)
    for (int k = 0; k <= K; k++) ans = min(ans, dp[N][j][k]);
  cout << ans << '\n';
  return 0;
}
