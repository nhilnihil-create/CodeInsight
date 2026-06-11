#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  const ll M = (ll)1e9 + 7;
  ll ans = 0;
  for (ll i = k; i <= n + 1; i++) {
    ll beg = (i - 1) * i / 2;
    ll end = (2 * n - i + 1) * i / 2;
    ll sum = (end - beg + 1) % M;
    // cout << beg << ' ' << end << ' ' << sum << endl;
    ans += sum;
    ans %= M;
  }
  cout << ans << '\n';
  return 0;
}
