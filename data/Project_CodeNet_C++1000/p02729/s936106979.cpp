#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  cout << (n * (n-1) / 2) + (m * (m-1) / 2) << '\n';

  return (0);
}
