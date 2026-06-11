#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n);
  vector<ll> b(m);
  for (long long i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  for (long long i = 0; i < m; i++) {
    cin >> b.at(i);
  }

  ll a_max = 0;
  ll b_max = 0;
  ll cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (k >= a.at(i)) {
      k -= a.at(i);
      a_max++;
      cnt++;
    } else {
      break;
    }
  }
  for (long long i = 0; i < m; i++) {
    if (k >= b.at(i)) {
      k -= b.at(i);
      b_max++;
      cnt++;
    } else {
      break;
    }
  }
  ll ans = cnt;
  for (long long i = a_max - 1; i >= 0; i--) {
    k += a.at(i);
    cnt--;
    for (long long j = b_max; j < m; j++) {
      if (k >= b.at(j)) {
        k -= b.at(j);
        b_max++;
        cnt++;
      } else {
        break;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
