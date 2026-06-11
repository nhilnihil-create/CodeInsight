#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  map<string,int> mp;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    ++mp[s];
  }

  int x = 0;
  for (auto e : mp) x = max(x, e.second);
  for (auto e : mp) if (e.second == x) cout << e.first << '\n';

  return (0);
}
