#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, a, b;
  cin >> n >> a >> b;

  ll sum = a + b;
  ll c = n % sum;

  ll ans = a * (n / sum);
  if (c <= a) ans += c;
  else ans += a;

  cout << ans << '\n';

  return (0);
}
