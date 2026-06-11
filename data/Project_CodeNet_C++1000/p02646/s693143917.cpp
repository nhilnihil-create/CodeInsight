#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
using namespace std;
typedef long long int ll;


int main() {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if (w >= v) {
    cout << "NO" << endl;
    return 0;
  }
  ll dis = max(a-b, b-a);
  ll sp = v-w;
  ll tt = (dis + sp - 1) / sp;
  if (tt > t) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
