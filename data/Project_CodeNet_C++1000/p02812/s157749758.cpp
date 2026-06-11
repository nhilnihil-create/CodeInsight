#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;

  int ans = 0;

  for (int i = 0; i < n-2; ++i) {
    string t = s.substr(i, 3);
    if (t == "ABC") ++ans;
  }

  cout << ans << '\n';

  return (0);
}