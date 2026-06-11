#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  llint a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  llint p = abs(a - b);
  llint q = (v - w) * t;
  if (p <= q) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}