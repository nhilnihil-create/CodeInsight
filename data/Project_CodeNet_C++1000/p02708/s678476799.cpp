#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll sum (ll l, ll r) {
  return (l + r) * (r - l + 1) / 2;
}

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = k; i <= n + 1; i++) {
    ll l = sum(0, i - 1);
    ll r = sum(n - i + 1, n);
    ans += (r - l + 1);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
