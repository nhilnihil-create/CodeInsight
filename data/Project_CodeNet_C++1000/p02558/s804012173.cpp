#include <bits/stdc++.h>

#include <atcoder/all>

// #LIB#

using namespace std;
using namespace atcoder;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#ifdef ONLINE_JUDGE
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');
#endif

int main() {
  ll n, q;
  cin >> n >> q;
  dsu d(n);
  rep(i, q) {
    ll t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      d.merge(u, v);
    } else {
      cout << d.same(u, v) << endl;
    }
  }
}
