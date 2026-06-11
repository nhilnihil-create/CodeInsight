#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int turn = 0;
  while (a > 0 && c > 0) {
    if (turn & 1) a -= d;
    else c -= b;
    
    ++turn;
  }

  if (a > 0) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}