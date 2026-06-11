#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, f[N][2];
char c[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> c + 1;
  f[0][0] = f[0][1] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = f[i - 1][0];
    f[i][1] = f[i - 1][1];
    if (c[i] == 'R') f[i][0]++;
    else f[i][1]++;
  }
  int ans = 1e9 + 7;
  for (int i = 0; i <= n; ++i) { ///red: [1 -> i]
    int redL = f[i][0], redR = f[n][0] - f[i][0];
    int whiteL = f[i][1], whiteR = f[n][1] - f[i][1];
    ans = min(ans, max(whiteL, redR));
  }
  cout << ans;
  return 0;
}
