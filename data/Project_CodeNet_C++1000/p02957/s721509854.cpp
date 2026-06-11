#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  int x = a + b;
  if (x & 1) cout << "IMPOSSIBLE\n";
  else cout << x / 2 << endl;

  return (0);
}
