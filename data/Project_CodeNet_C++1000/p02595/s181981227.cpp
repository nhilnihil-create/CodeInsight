#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d; cin >> n >> d;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    long long x, y; cin >> x >> y;
    ans += d >= sqrt(x * x + y * y);
  }
  cout << ans << endl;
}