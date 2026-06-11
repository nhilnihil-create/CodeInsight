#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve() {
  int n; cin >> n;
  int prv = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    if (prv <= v) {
      prv = v; continue;
    }
    ans += prv - v;
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    solve();
}
