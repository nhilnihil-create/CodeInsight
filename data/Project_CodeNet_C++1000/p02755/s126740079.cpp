#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  for (int i = 1; i <= 2000; ++i) {
    int c = i * 0.08;
    int d = i * 0.1;

    if (c == a && d == b) {
      cout << i << '\n';
      return (0);
    }
  }

  cout << -1 << '\n';

  return (0);
}
