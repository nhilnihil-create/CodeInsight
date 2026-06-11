#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int x)
{
  int res = 0;
  while (x) {
    x /= 10;
    ++res;
  }
  return res;
}

signed main()
{
  cout << fixed << setprecision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; ++i) if (f(i) & 1) ++ans;

  cout << ans << endl;

  return (0);
}
