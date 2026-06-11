#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, ans = 0;
  cin >> X >> Y;
  ans = max(400000 - 100000 * X, 0) + max(400000 - 100000 * Y, 0);
  if (X * Y == 1) ans += 400000;
  cout << ans << endl;
}