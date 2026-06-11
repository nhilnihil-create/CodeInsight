#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  auto check = [&](int x) {
    int ret = 0;
    rep(i, 0, n)
    {
      int t = (a[i] + x - 1) / x - 1;
      ret += t;
    }
    return ret <= k;
  };

  int l = 0, r = 1e9 + 1;
  while (r - l > 1)
  {
    int m = (l + r) / 2;
    if (check(m))
      r = m;
    else
      l = m;
  }

  cout << r << endl;

  return 0;
}