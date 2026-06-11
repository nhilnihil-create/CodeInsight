#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cout << fixed << setprecision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k, x;
  cin >> k >> x;

  for (int i = x - k + 1; i <= x + k - 1; ++i) {
    if (i != x - k + 1) cout << " ";
    cout << i;
  }

  cout << endl;

  return (0);
}
