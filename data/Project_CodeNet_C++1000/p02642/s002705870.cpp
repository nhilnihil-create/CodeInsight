#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }

  sort(a.begin(), a.end());

  vector<bool> ok(n, true);
  for (long i = 0; i < n; i++) {
    if (i != 0 && a.at(i) == a.at(i - 1)) {
      ok.at(i) = false;
      ok.at(i - 1) = false;
    }
    if (!ok.at(i)) {
      continue;
    }

    ll maxVal = a.at(n - 1);
    for (ll x = a.at(i) * 2; x <= maxVal; x += a.at(i)) {
      auto iter = lower_bound(a.begin(), a.end(), x);
      if (iter != a.end()) {
        if (*iter == x) {
          ok.at(distance(a.begin(), iter)) = false;
        }
      }
    }
  }
  ll ans = 0;
  for (auto x : ok) {
    if (x) {
      ans++;
    }
  }
  cout << ans << endl;
}
