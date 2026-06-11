#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t, u;
  int a, b;

  cin >> s >> t >> a >> b >> u;

  if (u == s) cout << a-1 << " " << b << '\n';
  else cout << a << " " << b-1 << '\n';

  return (0);
}
