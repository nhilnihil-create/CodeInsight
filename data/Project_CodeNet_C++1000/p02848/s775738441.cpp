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

  for (auto &c : s) {
    int d = c - 'A';
    d = (d + n) % 26;
    c = char('A' + d);
  }

  cout << s << '\n';

  return (0);
}
