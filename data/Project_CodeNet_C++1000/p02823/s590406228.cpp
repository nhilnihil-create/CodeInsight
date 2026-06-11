//#pragma GCC optimize("Ofast")

#ifdef LOCAL
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(x...)
#endif

//#define int ll

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define sz(x) int((x).size())

#ifdef ONLINE_JUDGE
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#else
mt19937 rng(1000 - 7);
#endif

const int N = 2e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;
//const int MOD = 1e9 + 7;
const ld eps = 1e-6;
const pii dir[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(9);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;

    if ((b - a) % 2 == 0) {
        cout << (b - a) / 2 << endl;
    }
    else {
        cout << (b - a + 1) / 2 + min(a - 1, n - b);
    }

    return 0;
}

