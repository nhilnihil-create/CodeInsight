#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long ans = max(b * d, a * c);
  a = abs(a);
  b = abs(b);
  c = abs(c);
  d = abs(d);
  ans = max(ans, -min(a, b) * min(c, d));
  cout << ans << endl;
  return 0;
}
