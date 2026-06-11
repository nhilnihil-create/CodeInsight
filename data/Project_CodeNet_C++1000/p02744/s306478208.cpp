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
  vector<string> ans;
  string s;
  function<void(int, int)> rec = [&](int i, int c) {
    if (i == N) {
      ans.push_back(s);
      return;
    }
    for (int j = 0; j < c; j++) {
      s += 'a' + j;
      rec(i + 1, c);
      s.pop_back();
    }
    s += 'a' + c;
    rec(i + 1, c + 1);
    s.pop_back();
  };
  rec(0, 0);
  sort(ans.begin(), ans.end());
  for (auto a : ans) cout << a << '\n';
  return 0;
}
