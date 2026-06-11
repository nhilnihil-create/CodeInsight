#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (ll i = 2; i * i <= n; i++) {
    ll count = 0;
    while (n % i == 0) {
      if (n % i == 0) {
        count++;
        n /= i;
      }
    }

    if (count != 0) {
      res.push_back({i, count});
    }
  }
  if (n != 1) {
    res.push_back({n, 1});
  }
  return res;
}

int main() {
  long n;
  cin >> n;

  auto pf = prime_factorize(n);
  ll ans = 0;

  for (auto x : pf) {
    ll now = 1;
    while (x.second >= now) {
      ans++;
      x.second -= now;
      now++;
    }
  }
  cout << ans << endl;
}
