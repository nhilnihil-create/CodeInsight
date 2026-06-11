#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

const ll MX = 1e18;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  int zero = 0;
  ll prod = 1;
  rep (i, n) if (a[i] == 0) zero++;
  if (zero) {
    cout << 0 << endl;
    return 0;
  }

  rep (i, n) {
    if (a[i] <= MX / prod) {
      prod *= a[i];
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  printf("%lld\n", prod);
  return 0;
}