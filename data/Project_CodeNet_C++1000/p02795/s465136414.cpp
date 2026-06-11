#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w, n;
  cin >> h >> w >> n;

  int x = max(h, w);
  cout << (n + x - 1) / x << endl;

  return (0);
}
