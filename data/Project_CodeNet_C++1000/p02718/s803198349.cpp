#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a, a+n, greater<int>());

  int d = a[m-1], sum = accumulate(a, a+n, 0);

  if (d * 4 * m < sum) cout << "No\n";
  else cout << "Yes\n";

  return (0);
}
