#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int n; cin >> n;
  int res = 0;
  for (int i = 1; i <= n; ++i) res += i * (n - i + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    res -= u * (n - v + 1);
  }
  cout << res;
  return 0;
}