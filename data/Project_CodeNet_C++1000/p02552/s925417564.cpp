#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    bool x;
    cin >> x;
    cout << !x;
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