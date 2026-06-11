#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  array<int, 3> a = {300000, 200000, 100000};

  int ans = 0;
  if (x < 4)
    ans += a[x - 1];
  if (y < 4)
    ans += a[y - 1];
  if (x == 1 && y == 1)
    ans += 400000;

  cout << ans << endl;
}