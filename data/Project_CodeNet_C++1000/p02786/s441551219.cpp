#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll h;
  cin >> h;

  ll ans = 1;

  while (h) {
    h /= 2;
    ans *= 2;
  }

  cout << ans-1 << '\n';

  return (0);
}
