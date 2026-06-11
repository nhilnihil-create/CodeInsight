#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n, m, x;
  cin >> n >> m >> x;
  vector<ll> c(n);
  vector<vector<long>> a(n, vector<long>(m));

  for (long i = 0; i < n; i++) {
    cin >> c.at(i);
    for (long j = 0; j < m; j++) {
      cin >> a.at(i).at(j);
    }
  }

  ll ans = 0;
  for (long i = 0; i < n; i++) {
    ans += c.at(i);
  }
  ans++;
  ll init = ans;

  for (long bit = 0; bit < (1 << n); bit++) {
    vector<long> u(m, 0);
    ll sum = 0;
    for (long i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        sum += c.at(i);
        for (long j = 0; j < m; j++) {
          u.at(j) += a.at(i).at(j);
        }
      }
    }
    bool ok = true;
    for (long i = 0; i < m; i++) {
      if (u.at(i) < x) {
        ok = false;
      }
    }
    if (ok) {
      ans = min(ans, sum);
    }
  }

  if (ans == init) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
