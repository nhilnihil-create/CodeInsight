#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  int x[n][d];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> x[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int d2 = 0;
      for (int k = 0; k < d; k++) {
        d2 += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      }
      int d1 = round(sqrt(d2));
      if (d2 == d1 * d1) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
