#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;

  ll total = 0;
  vector<ll> a(n);
  vector<ll> b(n);

  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }

  set<ll> divisors;
  for (ll i = 1; i*i <= total; i++) {
    if (total % i == 0) {
      divisors.insert(i);
      divisors.insert(total/i);
    }
  }

  ll ans = 1;
  for (auto x : divisors) {
    for (ll i = 0; i < n; i++) b[i] = a[i] % x;
    sort(b.begin(), b.end());

    ll total = 0;
    ll cnt = 0;
    ll i = 0, j = n - 1;
    while (i <= j) {
      if (total <= 0) {
        total += b[i];
        cnt += b[i];
        i++;
      } else {
        total -= x - b[j];
        j--;
      }
    }
    cnt += (total + x) % x;
    if (cnt <= k) ans = x;
  }

  cout << ans << endl;
}
