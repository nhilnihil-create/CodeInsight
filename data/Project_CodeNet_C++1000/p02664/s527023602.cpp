#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string t;
  cin >> t;

  for (auto &c : t) if (c == '?') c = 'D';
  cout << t << '\n';

  return (0);
}
