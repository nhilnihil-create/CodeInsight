#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;

  if ((a == b && b != c) || (a == c && b != a) || (b == c && a != b)) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
