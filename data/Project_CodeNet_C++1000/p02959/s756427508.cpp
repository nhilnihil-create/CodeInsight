#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll n, sum, t;

int main() {
  cin >> n;
  vector<ll> a(n+1);
  vector<ll> b(n);
  rep (i, n+1) {
    cin >> a[i];
  }
  sum = 0;
  rep (i, n) {
    cin >> b[i];
    sum += b[i];
  }
  rep (i, n) {
    b[i] -= a[i];
    if (b[i] < 0) b[i] = 0;
    if (b[i] > 0) {
      t = min(a[i+1], b[i]);
      a[i+1] -= t;
      b[i] -= t;
    }
  }
  rep (i, n) {
    sum -= b[i];
  }
  cout << sum << endl;
  return 0;
}
