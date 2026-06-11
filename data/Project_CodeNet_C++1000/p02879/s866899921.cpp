#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;

  if (x < 10 && y < 10) cout << x * y << endl;
  else cout << -1 << endl;

  return (0);
}
