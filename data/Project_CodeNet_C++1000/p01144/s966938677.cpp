#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n, m;
  while (cin >> n >> m, n) {
    int cnt[11] = {};
    int d, p;
    for (int i = 0; i < n; i++) {
      cin >> d >> p;
      cnt[p] += d;
    }

    for (int i = 10; i >= 0; i--) {
      if (m < cnt[i]) {
        cnt[i] -= m;
        m = 0;
      } else {
        m -= cnt[i];
        cnt[i] = 0;
      }
    }

    int ans = 0;
    for (int i = 0; i <= 10; i++) {
      ans += cnt[i] * i;
    }
    cout << ans << endl;
  }

  return 0;
}
