#include <iostream>
using namespace std;
typedef long long ll;
int k, q;
int d[5000];

int main() {
  cin >> k >> q;
  for (int i = 0; i < k; i++)
    cin >> d[i];
  for (int qi = 0; qi < q; qi++) {
    ll n, x, m;
    cin >> n >> x >> m;
    ll last = x;
    ll eq = 0;
    for (int i = 0; i < k; i++) {
      ll cnt = (n - 2 - i + k) / k;
      last += ((ll)d[i] % m) * cnt;
      if (d[i] % m == 0) eq += cnt;
    }
    ll ans = (n - 1) - (last / m - x / m) - eq;
    cout << ans << endl;
  }
  return 0;
}