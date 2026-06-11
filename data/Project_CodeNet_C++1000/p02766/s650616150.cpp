#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int ans = 0;

  while (n) {
    n /= k;
    ++ans;
  }

  cout << ans << '\n';

  return (0);
}
