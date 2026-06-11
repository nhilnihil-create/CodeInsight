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
  string s, t;
  cin >> s >> t;
  int N = s.length();
  long long to[N][26];
  fill(to[N - 1], to[N - 1] + 26, INF);
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) to[i][j] = to[i + 1][j] + 1;
    to[i][s[i + 1] - 'a'] = 1;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) to[i][j] = to[(i + 1) % N][j] + 1;
    to[i][s[(i + 1) % N] - 'a'] = 1;
  }
  long long ans = 0;
  long long cur = N - 1;
  for (int i = 0; i < (int)t.length(); i++) {
    debug(i);
    long long tmp = to[cur][t[i] - 'a'];
    if (tmp >= INF) {
      ans = -1;
      break;
    }
    ans += tmp;
    (cur += tmp) %= N;
  }
  cout << ans << '\n';
  return 0;
}
