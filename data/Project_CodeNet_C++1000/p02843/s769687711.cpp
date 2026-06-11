#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;

  cout << ((x / 100 * 5) >= (x % 100)) << endl;

  return (0);
}
