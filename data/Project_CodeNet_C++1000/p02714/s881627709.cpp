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
  string S;
  cin >> S;
  long long cnt[3] = {0, 0, 0};
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') cnt[0]++;
    if (S[i] == 'G') cnt[1]++;
    if (S[i] == 'B') cnt[2]++;
  }
  long long ans = 0;
  for (int j = 1; j + 1 < N; j++) {
    for (int d = 1; j - d >= 0 && j + d < N; d++) {
      int i = j - d, k = j + d;
      if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) ans--;
    }
  }
  ans += cnt[0] * cnt[1] * cnt[2];
  cout << ans << endl;
  return 0;
}
