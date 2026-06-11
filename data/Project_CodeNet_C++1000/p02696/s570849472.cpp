#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, n;
  cin >> a >> b >> n;

  ll x = min(b - 1, n);
  cout << (a*x / b) - a * (x / b) << '\n';

  return (0);
}