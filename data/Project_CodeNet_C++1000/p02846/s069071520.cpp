#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll t1, a1, b1, t2, a2, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  a1 *= t1;
  a2 *= t2;
  b1 *= t1;
  b2 *= t2;
  a2 += a1;
  b2 += b1;
  if (a2 == b2) {
    cout << "infinity" << endl;
    return 0;
  }

  if (a2 < b2) {
    swap(a1, b1);
    swap(a2, b2);
  }

  ll d = a2 - b2;
  ll c = b1 - a1;
  ll ans = 0;
  if (c > 0) {
    ans = (c - 1) / d + 1;
    ans *= 2;
    ans--;
    if (c % d == 0) ans++;
  }

  cout << ans << endl;

  return 0;
}