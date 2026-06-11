#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int result = max(a * c, max(a * d, max(b * c, b * d)));
    cout << result;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}