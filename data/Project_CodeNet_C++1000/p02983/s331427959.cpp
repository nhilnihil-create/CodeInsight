#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, r;
  cin >> l >> r;
  if (l / 2019 != r / 2019) {
    cout << 0 << endl;
    return 0;
  }
  l %= 2019;
  r %= 2019;
  int ans = 2019;
  for (int i = l; i < r; i++) {
    for (int j = l + 1; j <= r; j++) {
      int x = (i * j) % 2019;
      if (x < ans) ans = x;
    }
  }
  cout << ans << endl;
  return 0;
}