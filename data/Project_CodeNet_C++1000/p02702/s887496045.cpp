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
  string S;
  cin >> S;
  long long cnt[2019];
  fill(cnt, cnt + 2019, 0);
  int sum = 0, pw10 = 1;
  for (int i = S.length() - 1; i >= 0; i--) {
    sum = ((S[i] - '0') * pw10 + sum) % 2019;
    debug(sum);
    pw10 = pw10 * 10 % 2019;
    cnt[sum]++;
  }
  //   debugArray(cnt, 2019);
  long long ans = cnt[0];
  for (int i = 0; i < 2019; i++) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
