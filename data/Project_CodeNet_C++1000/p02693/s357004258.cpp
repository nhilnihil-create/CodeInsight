#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k, a, b;
  cin >> k >> a >> b;

  int x = (a - 1) / k;
  int y = b / k;

  cout << (y - x > 0 ? "OK" : "NG") << '\n';

  return (0);
}
