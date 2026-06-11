//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("fma,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define x first
#define y second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;
    int d = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        d += y;
        if (d <= x) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
