#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll h, w;
  cin >> h >> w;

  if (h == 1 || w == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll ans = 0;
  if (w % 2 == 0) {
    ans = w / 2 * h;
    cout << ans << endl;
    return 0;
  }

  for (ll i = 0; i < h; i++) {
    if (i % 2 == 0) {
      ans += w / 2 + 1;
    } else {
      ans += w / 2;
    }
  }
  cout << ans << endl;
}
