#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Range {
  ll l, r;
};

int main() {
  int n;  cin >> n;
  vector<Range> ranges;
  // cerr << "d a r l" << endl;
  ll r = 1, e;
  vector<ll> lr, la;
  for (int d = 0; d <= n; ++d) {
    int a; cin >> a;
    la.push_back(a);
    ll nr = min(r*2, 1LL<<50);
    if (d == 0) nr = 1;
    // cerr << d << " " << a << " " << r << " " << nr << endl;
    if (a > nr) {
      cout << -1 << endl;
      return 0;
    }
    if (d < n) {
      nr -= a;
      r = nr;
      lr.push_back(r);
      // cout << d << " " << r << endl;
    }
    else {
      e = a;
    }
  }
  ll ans = e;
  for (int i = n-1; i >= 0; --i) {
    ll ne = min(e, lr[i])+la[i];
    ans += ne;
    // cout << i << ":" << ne << endl;
    e = ne;
  }
  cout << ans << endl;
}
