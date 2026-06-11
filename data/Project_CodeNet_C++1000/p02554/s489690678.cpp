#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long ans1 = 1, ans2 = 2, ans3 = 1;
  for (int i = 0; i < n; i++) {
    (ans1 *= 10) %= md;
    (ans2 *= 9) %= md;
    (ans3 *= 8) %= md;
  }
  (ans1 -= ans2 - ans3 - md) %= md;
  cout << ans1 << endl;
  return 0;
}
