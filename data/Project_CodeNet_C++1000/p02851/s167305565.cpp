#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

ll a[200100], asum[200100], val[200100];
int main() {
  ll n, k;
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  rep(i, n) asum[i + 1] = asum[i] + a[i];
  rep(i, n + 1) val[i] = (asum[i] - i) % k;
  // multiset<ll> s;
  map<ll, ll> m;
  ll res = 0;
  rep(i, n + 1) {
    // if (i - k >= 0) s.erase(s.find(val[i - k]));
    // res += s.count(val[i]);
    // s.insert(val[i]);
    if (i - k >= 0) --m[val[i - k]];
    res += m[val[i]];
    ++m[val[i]];
  }
  cout << res << endl;
}
