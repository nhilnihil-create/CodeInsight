#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  int ans = x / 500 * 1000;
  ans += ((x - x / 500 * 500) / 5 * 5);
  cout << ans << '\n';
  return 0;
}
