#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int sum = 0;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;

    sum += a;
  }

  int ans = n - sum;
  cout << (ans < 0 ? -1 : ans) << '\n';

  return (0);
}