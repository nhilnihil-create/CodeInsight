#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int t[2];
  cin >> t[0] >> t[1];
  ll a[2], b[2];
  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];

  if(a[0] < b[0]) {
    swap(a[0], b[0]);
    swap(a[1], b[1]);
  }

  ll c[2] = {a[0] - b[0], a[1] - b[1]};
  ll d[2] = {c[0] * t[0], c[1] * t[1]};
  if(0 < d[0] + d[1]) {
    cout << 0 << endl;
    return 0;
  }
  if(d[0] == -d[1]) {
    cout << "infinity" << endl;
    return 0;
  }

  ll dx = -d[1] - d[0];
  ll ans = 1;
  ans += 2 * (d[0] / dx);
  if(d[0] % dx == 0) ans--;
  cout << ans << endl;
  return 0;
}