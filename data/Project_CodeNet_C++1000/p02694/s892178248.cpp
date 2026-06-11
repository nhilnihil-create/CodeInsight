#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll x;
  cin >> x;

  ll now = 100;
  int ans = 0;
  
  while (now < x) {
    now += now / 100;
    ++ans;
  }

  cout << ans << '\n';

  return (0);
}