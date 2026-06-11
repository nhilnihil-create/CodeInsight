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
  int N;
  cin >> N;
  pair<long long, int> Ai[N];
  for (int i = 0; i < N; i++) {
    cin >> Ai[i].first;
    Ai[i].second = i + 1;
  }
  sort(Ai, Ai + N);
  long long ans = 0;
  long long dp[N + 1][N + 1];
  for (int x = 0; x <= N; x++) fill(dp[x], dp[x] + N + 1, 0);
  dp[0][0] = 0;
  for (int x = 0; x <= N; x++) {
    for (int y = 0; x + y + 1 <= N; y++) {
      int i;
      long long A;
      tie(A, i) = Ai[N - (x + y + 1)];
      dp[x + 1][y] = max(dp[x + 1][y], dp[x][y] + A * abs(x + 1 - i));
      dp[x][y + 1] = max(dp[x][y + 1], dp[x][y] + A * abs(N - y - i));
    }
    ans = max(ans, dp[x][N - x]);
  }
  cout << ans << endl;
  return 0;
}
