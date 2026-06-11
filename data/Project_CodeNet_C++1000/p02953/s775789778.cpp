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

  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  int mx = 0;
  for (int i = 0; i < n; ++i) {
    if (mx <= h[i]) mx = h[i];
    else {
      if (mx - h[i] >= 2) {
        cout << "No\n";
        return (0);
      }
    }
  }

  cout << "Yes\n";

  return (0);
}
