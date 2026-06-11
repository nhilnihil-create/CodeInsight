#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int cnt[2010] = {};
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      cnt[min(j - i, abs(x - i) + abs(j - y) + 1)]++;
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    cout << cnt[i] << '\n';
  }
  return 0;
}