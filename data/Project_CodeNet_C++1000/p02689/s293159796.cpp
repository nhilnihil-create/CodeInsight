#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> h(n);
  for (ll &x : h) {
    cin >> x;
  }
  vector<set<ll>> g(n);

  for (long i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g.at(a).insert(b);
    g.at(b).insert(a);
  }

  ll ans = 0;
  for (long i = 0; i < n; i++) {
    bool ok = true;
    for (auto x : g.at(i)) {
      if (h.at(i) <= h.at(x)) {
        ok = false;
      }
    }
    if (ok) {
      ans++;
    }
  }

  cout << ans << endl;
}
