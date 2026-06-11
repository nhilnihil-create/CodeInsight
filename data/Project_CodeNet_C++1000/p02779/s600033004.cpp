#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  set<int> s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (s.count(a)) {
      cout << "NO\n";
      return (0);
    }

    s.emplace(a);
  }

  cout << "YES\n";

  return (0);
}
