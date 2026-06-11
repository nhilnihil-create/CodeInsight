#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.length();
  int ans = 0;

  for (int i = 0; i < n/2; ++i) {
    if (s[i] == s[n-i-1]) continue;
    ++ans;
  }

  cout << ans << '\n';

  return (0);
}