#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1), b(n);
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll cnt = 0;
  for (int i = n; i > 0; i--) {
    if (a[i] >= b[i - 1]) {
      cnt += b[i - 1];
      b[i - 1] = 0;
    } else {
      cnt += a[i];
      b[i - 1] -= a[i];
      if (b[i - 1] <= a[i - 1]) {
        cnt += b[i - 1];
        a[i - 1] -= b[i - 1];
      } else {
        cnt += a[i - 1];
        a[i - 1] = 0;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
