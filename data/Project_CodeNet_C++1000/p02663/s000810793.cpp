#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  int s = 60 * h1 + m1;
  int g = 60 * h2 + m2;

  cout << g - s - k << '\n';

  return (0);
}
