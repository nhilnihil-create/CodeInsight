#include <bits/stdc++.h>
#include <array>
#define int long long
using namespace std;
signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  bool yes = false;
  int n;
  cin >> n;
  vector<array<int, 2>> d(n);
  for (int i = 0; i < n; ++i)
    cin >> d[i][0] >> d[i][1];
  for (int i = 0; i < n; ++i) {
    if (i + 2 < n && d[i][0] == d[i][1] &&
      d[i + 1][0] == d[i + 1][1] &&
      d[i + 2][0] == d[i + 2][1])
      yes = true;
  }
  cout << (yes ? "Yes\n" : "No\n");
  return 0;
}