#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];
  while (k--) {
    int b[n] = {};
    int m = n * 2;
    for (int i = 0; i < n; i++) {
      m = min(m, a[i]);
      b[max(0, i - a[i])]++;
      if (i + a[i] + 1 < n) b[i + a[i] + 1]--;
    }
    if (m >= n) break;
    rep(i, n - 1) b[i + 1] += b[i];
    memcpy(a, b, sizeof(b));
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
}