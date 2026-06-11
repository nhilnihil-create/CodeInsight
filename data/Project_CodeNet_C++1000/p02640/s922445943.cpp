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
const string file = "3";



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    /// a + b = x
    /// 2a + 4b = y

    int x, y;
    cin >> x >> y;

    if (y % 2 != 0) {
        return cout << yn(0) << "\n", 0;
    }

    int z = y - 2 * x;
    if (z < 0 || z % 2 != 0) {
        return cout << yn(0) << "\n", 0;
    }

    int b = z / 2;
    int a = x - b;

    if (a < 0) {
        return cout << yn(0) << "\n", 0;
    }

    cout << yn(1) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
