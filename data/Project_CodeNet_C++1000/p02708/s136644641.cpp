#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  for (ll i = k; i <= n+1; ++i) {
    ll l = (i + i*i) / 2;
    ll r = i * (2*(n+1) - i + 1) / 2;

    ans += (r - l + 1);
    ans %= MOD;
  }

  cout << (ans + MOD) % MOD << '\n';

  return (0);
}
