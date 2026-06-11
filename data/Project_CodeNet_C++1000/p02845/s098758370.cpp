#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n), c(n), d(n);
  d[0] = 3;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ll x = a[i];
    if (d[x] == 0) {
      cout << 0 << endl;
      return 0;
    }
    c[i] = d[x];
    d[x] -= 1;
    d[x + 1] += 1;
  }

  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ans *= c[i];
    ans %= MOD;
  }

  cout << ans << endl;
}