#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;

  int d = 360 / __gcd(360, x) * x;
  cout << d / x << '\n';

  return (0);
}
