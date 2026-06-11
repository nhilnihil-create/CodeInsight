#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> b(n-1);
  for (int i = 0; i < n-1; ++i) cin >> b[i];

  int ans = b[0];
  for (int i = 0; i < n-2; ++i) ans += min(b[i], b[i+1]);

  cout << ans + b[n-2] << endl;

  return (0);
}
