#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll cnt = 0;
  ll ans = 0;
  const ll mod = 1000000007;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) cnt++;
    }
  }
  ans = (cnt * k) % mod;

  ll nC2 = k * (k - 1) / 2 % mod;
  for (int i = 0; i < n; i++) {
    ll cnt2 = 0;
    for (int j = 0; j < n; j++) {
      if (a[i] > a[j]) cnt2++;
    }
    ll tmp = cnt2 * nC2 % mod;
    ans = (ans + tmp) % mod;
  }

  cout << ans << endl;
}