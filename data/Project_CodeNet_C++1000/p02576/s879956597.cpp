#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve() {
  int n, x, t; cin >> n >> x >> t;
  cout << t * ((n + x - 1) / x);
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    solve();
}
