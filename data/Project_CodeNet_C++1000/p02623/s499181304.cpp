/**
 * author:  virenkathiriya96
 * created: 2020.08.31 15:22:11
**/

#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int &x: a) cin >> x;
  for (int &x: b) cin >> x;
  vector<int> suma(n, 0), sumb(m, 0);
  suma[0] = a[0], sumb[0] = b[0];
  for (int i = 1; i < n; i++) {
    suma[i] = suma[i - 1] + a[i];
  }
  for (int j = 1; j < m; j++) {
    sumb[j] = sumb[j - 1] + b[j];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int rem = k - suma[i];
    if (rem == 0) {
      ans = max(ans, i + 1);
    } else if (rem > 0) {
      ans = max(ans, i + 1);
      auto it = upper_bound(sumb.begin(), sumb.end(), rem);
      if (it != sumb.begin()) {
        it--;
        int index = it - sumb.begin();
        ans = max(i + 1 + index + 1, ans);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int rem = k - sumb[i];
    if (rem == 0) {
      ans = max(ans, i + 1);
    } else if (rem > 0) {
      ans = max(ans, i + 1);
      auto it = upper_bound(suma.begin(), suma.end(), rem);
      if (it != suma.begin()) {
        it--;
        int index = it - suma.begin();
        ans = max(i + 1 + index + 1, ans);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
