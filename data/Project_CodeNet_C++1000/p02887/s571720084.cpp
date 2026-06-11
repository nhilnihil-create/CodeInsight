#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < n-1; ++i) ans += (s[i] != s[i+1]);

  cout << ans+1 << endl;

  return (0);
}
