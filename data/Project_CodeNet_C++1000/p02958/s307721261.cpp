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
  vector<int> p(N), v(N);
  iota(v.begin(), v.end(), 1);
  for (int i = 0; i < N; i++) cin >> p[i];
  bool isok = p == v;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      swap(p[i], p[j]);
      isok |= p == v;
      swap(p[i], p[j]);
    }
  cout << (isok ? "YES" : "NO") << '\n';
  return 0;
}
