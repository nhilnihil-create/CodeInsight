#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "Yes" : "No")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 2e5 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "2";



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ans = 0;
    while (a >= b) {
        ans++;
        b *= 2;
    }

    while (b >= c) {
        ans++;
        c *= 2;
    }

    cout << yn(ans <= k) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
