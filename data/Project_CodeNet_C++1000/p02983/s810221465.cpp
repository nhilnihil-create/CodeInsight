#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll l, r;
  cin >> l >> r;
  r = min(r, l + 4038);
  ll ans = 2019;
  for (ll i = l; i <= r; i++)
  {
    for (ll j = i + 1; j <= r; j++)
    {
      ans = min(ans, (i * j) % 2019);
    }
  }
  cout << ans << endl;
}
