#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long int ll;

int main() {
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  ll a = t1 * a1 - t1 * b1;
  ll b = t2 * a2 - t2 * b2;
  if (a > 0) {
    a *= -1;
    b *= -1;
  }
  if (a + b < 0) cout << 0 << endl;
  else if (a + b == 0) cout << "infinity" << endl;
  else {
    ll s = -a / (a + b);
    ll t = -a % (a + b);
    if (t == 0) cout << s * 2 << endl;
    else cout << s * 2 + 1 << endl;
  }
  return 0;
}