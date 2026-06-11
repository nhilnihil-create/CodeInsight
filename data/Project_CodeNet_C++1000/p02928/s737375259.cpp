#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll p = 0, q = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i < j && a[i] > a[j]) p++;
      if (a[i] > a[j]) q++;
    }
  }

  // cerr << p << " " << q << endl;
  ll x = (p * k) % mod;
  ll y = (k * (k - 1) / 2) % mod * q;
  ll ans = (x + y) % mod;
  cout << ans << endl;
  return 0;
}
