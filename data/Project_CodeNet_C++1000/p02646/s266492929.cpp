#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  long long d = abs(a - b);
  if (v > w && d <= (v - w) * t) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}