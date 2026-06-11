#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i <= 50000; ++i) {
    int x = i * 1.08;
    if (x == n) {
      cout << i << '\n';
      return 0;
    }
  }

  puts(":(");

  return (0);
}
