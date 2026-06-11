#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                             \
  cerr << __LINE__ << ": " << #x << " = {";          \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) { \
    cerr << ((hoge) ? "," : "") << x[hoge];          \
  }                                                  \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  string s = S.substr(0, S.length() / 2),
         t = S.substr(S.length() / 2 + 1, S.length() / 2);
  bool isok = true;
  for (int i = 0; i < s.length() / 2; i++)
    isok &= s[i] == s[s.length() - 1 - i];
  isok &= s == t;
  cout << (isok ? "Yes" : "No") << endl;
  return 0;
}
