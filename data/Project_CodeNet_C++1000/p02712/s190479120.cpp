#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 1; i <= n; ++i) if (i % 3 && i % 5) ans += i;

  cout << ans << '\n';
  
  return (0);
}
