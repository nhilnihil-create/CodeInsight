#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ll f(ll n) {
//   if (n < 2) return 1;
//   return n * f(n - 2);
// }

ll count_d(ll n, ll d) {
  ll res = 0, dd = d;
  while (dd <= n) {
    res += n / d;
    dd *= d;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  //   rep(i, 10) cout << f(i) << endl;
  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0, d = 10;
  while (d <= n) {
    ans += n / d;
    d *= 5;
  }

  cout << ans << endl;
  return 0;
}
