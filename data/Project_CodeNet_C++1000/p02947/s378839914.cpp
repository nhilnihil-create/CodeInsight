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
  string s[N];
  map<string, long long> cnt;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    cnt[s[i]]++;
  }
  long long ans = 0;
  for (auto p : cnt) {
    ans += p.second * (p.second - 1) / 2;
  }
  cout << ans << '\n';

  return 0;
}
