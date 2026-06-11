#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll x;
  cin >> x;

  for (ll i = -200; i <= 200; ++i) {
    for (ll j = -200; j <= 200; ++j) {
      if (pow(i, 5) - pow(j, 5) == x) {
        cout << i << " " << j << '\n';
        return (0);
      }
    }
  }

  return (0);
}
