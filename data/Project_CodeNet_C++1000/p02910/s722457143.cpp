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

  for (int i = 0; i < n; ++i) {
    if ((i & 1) && s[i] == 'R') {
      cout << "No\n";
      return (0);
    }

    if (!(i & 1) && s[i] == 'L') {
      cout << "No\n";
      return (0);
    }
  }

  cout << "Yes\n";

  return (0);
}
