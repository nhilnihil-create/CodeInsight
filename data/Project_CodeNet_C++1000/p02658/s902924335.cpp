#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1;
  rep(i, n) {
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  rep(i, n) {
    if (ans > 1000000000000000000 / a[i]) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }
  cout << ans << endl;
  return 0;
}