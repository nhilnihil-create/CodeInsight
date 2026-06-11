#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;

  if (a > b) {
    ll c = a - v * t;
    ll d = b - w * t;

    if (c <= d) cout << "YES\n";
    else cout << "NO\n";
  } else {
    ll c = a + v * t;
    ll d = b + w * t;

    if (c >= d) cout << "YES\n";
    else cout << "NO\n";
  }

  return (0);
}
