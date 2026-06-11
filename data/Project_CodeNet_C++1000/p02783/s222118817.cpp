#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, a;
  cin >> h >> a;
  int ans = 0;
  while (h > 0) {
    h -= a;
    ans++;
  }
  cout << ans << '\n';
  return 0;
}