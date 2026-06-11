#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll r, c;
  cin >> r >> c;

  if (r == 1 || c == 1) {
    cout << 1 << '\n';
    return (0);
  }

  cout << (r * c + 1) / 2 << '\n';

  return (0);
}