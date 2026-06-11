#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b;
  cin >> a >> b;

  cout << a / __gcd(a, b) * b << '\n';

  return (0);
}