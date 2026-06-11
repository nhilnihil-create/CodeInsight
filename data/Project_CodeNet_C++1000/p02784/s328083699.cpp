#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, n;
  cin >> h >> n;

  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll sum = accumulate(a, a+n, 0);

  if (sum >= h) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
