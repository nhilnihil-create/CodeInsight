#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int t1, t2;
ll a1, a2, b1, b2;

int main() {
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if (a1 < b1) {
    swap(a1, b1);
    swap(a2, b2);
  }
  ll d = (b1 * t1 + b2 * t2) - (a1 * t1 + a2 * t2);
  if (d < 0) {
    cout << 0 << endl;
    return 0;
  }
  if (d == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  ll d0 = a1 * t1 - b1 * t1;
  ll k = d0 / d;
  ll ans = 2 * k + 1;
  if (d * k == d0) ans--;
  cout << ans << endl;
  return 0;
}