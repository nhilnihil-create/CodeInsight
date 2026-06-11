#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  string s, t;
  for (int i = 0; i < b; ++i) s += to_string(a);
  for (int i = 0; i < a; ++i) t += to_string(b);

  cout << min(s, t) << '\n';

  return (0);
}
