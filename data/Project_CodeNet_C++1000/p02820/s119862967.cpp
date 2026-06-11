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
  int N, K;
  cin >> N >> K;
  long long R, S, P;
  cin >> R >> S >> P;
  string T;
  cin >> T;
  auto score = [&](char c, int x) {
    if (c == 'r' && x == 2) return P;
    if (c == 's' && x == 0) return R;
    if (c == 'p' && x == 1) return S;
    return 0ll;
  };
  long long dp[K][3];
  for (int i = 0; i < K; i++)
    for (int j = 0; j < 3; j++) dp[i][j] = score(T[i], j);
  for (int i = K; i < N; i++) {
    long long tmp[3] = {0, 0, 0};
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        if (k != j) tmp[j] = max(tmp[j], dp[i % K][k] + score(T[i], j));
    for (int j = 0; j < 3; j++) dp[i % K][j] = tmp[j];
  }
  long long ans = 0;
  for (int i = 0; i < K; i++) ans += max({dp[i][0], dp[i][1], dp[i][2]});
  cout << ans << '\n';
  return 0;
}
