#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  set<string> appear;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    appear.emplace(s);
  }

  cout << appear.size() << '\n';

  return (0);
}