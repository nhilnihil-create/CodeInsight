#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, k;
  cin >> a >> b >> k;

  if (k <= a) cout << a - k << " " << b << '\n';
  else if (k <= a + b) cout << 0 << " " << b - (k - a) << '\n';
  else cout << 0 << " " << 0 << '\n';

  return (0);
}