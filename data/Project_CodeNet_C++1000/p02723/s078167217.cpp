#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  if (s[2] == s[3] && s[4] == s[5]) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
