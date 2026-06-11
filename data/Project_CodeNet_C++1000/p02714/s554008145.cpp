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

  map<char,ll> mp;
  for (int i = 0; i < n; ++i) ++mp[s[i]];

  ll ans = mp['R'] * mp['G'] * mp['B'];

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int k = j + (j - i);
      if (k >= n) continue;
      
      if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) --ans;
    }
  }

  cout << ans << '\n';

  return (0);
}
