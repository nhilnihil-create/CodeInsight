#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if (a1 > b1 && a2 > b2) {
    cout << 0 << endl;
    return 0;
  }
  if (b1 > a1 && b2 > a2) {
    cout << 0 << endl;
    return 0;
  }
  if (a1 > b1 && (a1 * t1 + a2 * t2 > b1 * t1 + b2 * t2)) {
    cout << 0 << endl;
    return 0;
  }
  if (a1 < b1 && (a1 * t1 + a2 * t2 < b1 * t1 + b2 * t2)) {
    cout << 0 << endl;
    return 0;
  }
  if (a1 * t1 + a2 * t2 == b1 * t1 + b2 * t2) {
    cout << "infinity" << endl;
    return 0;
  }
  if (a1 > b1 && (a1 * t1 + a2 * t2 < b1 * t1 + b2 * t2)) {
    ll dif = b1 * t1 + b2 * t2 - (a1 * t1 + a2 * t2);
    ll ans = ((a1 * t1 - b1 * t1) / dif) * 2;
    if ((a1 * t1 - b1 * t1) % dif == 0) {
      ans -= 1;
    }
    cout << ans + 1 << endl;
    return 0;
  }
  if (a1 < b1 && (a1 * t1 + a2 * t2 > b1 * t1 + b2 * t2)) {
    ll dif = (a1 * t1 + a2 * t2) - b1 * t1 - b2 * t2;
    ll ans = ((b1 * t1 - a1 * t1) / dif) * 2;
    if ((b1 * t1 - a1 * t1) % dif == 0) {
      ans -= 1;
    }
    cout << ans + 1 << endl;
    return 0;
  }
}
