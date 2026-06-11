#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  if (k % 2 == 0 || k % 5 == 0) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 1, a = 7;
  while (true) {
    if (a % k == 0) {
      cout << ans << '\n';
      return 0;
    }
    ans++;
    a *= 10;
    a += 7;
    a %= k;
  }
  return 0;
}
