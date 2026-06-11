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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  fenwick_tree<ll> t(n);
  rep(i, n) t.add(i, a[i]);
  rep(i, q) {
    ll qi, p, x;
    cin >> qi >> p >> x;
    if (qi == 0) {
      t.add(p, x);
    } else {
      cout << t.sum(p, x) << endl;
    }
  }
}
