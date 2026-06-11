#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll k, q;
  cin >> k >> q;

  vector<ll> d(k);
  for (ll i = 0; i < k; i++) {
    cin >> d[i];
  }

  for (ll i = 0; i < q; i++) {
    ll n, x, m;
    cin >> n >> x >> m;

    ll zeros = 0;
    vector<ll> dmod(k);
    for (ll j = 0; j < k; j++) {
      dmod[j] = d[j] % m;
      if (dmod[j] == 0) {
        if (j < (n - 1) % k) {
          zeros += (n - 1) / k + 1;
        } else {
          zeros += (n - 1) / k;
        }
      }
    }

    ll last = x;
    for (ll j = 0; j < k; j++) {
      if (j < (n - 1) % k) {
        last += dmod[j] * ((n - 1) / k + 1);
      } else {
        last += dmod[j] * ((n - 1) / k);
      }
    }

    ll ans = n - 1 - (last / m - x / m + zeros);
    cout << ans << endl;
  }
}