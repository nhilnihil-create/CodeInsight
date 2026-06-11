#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  int ans = (max(0, 4 - x)) * 100000;
  ans += (max(0, 4 - y)) * 100000;
  if (x == 1 && y == 1) ans += 400000;
  cout << ans;
  return 0;
}
