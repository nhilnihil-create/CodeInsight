#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;

main() {
  ios :: sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= (int)1e6; ++i) {
    if ((int)(i * 0.08) == a && (int)(i * 0.1) == b) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}