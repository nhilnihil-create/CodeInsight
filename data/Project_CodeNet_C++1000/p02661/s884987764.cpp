#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 2e5 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "2";

int a[siz], b[siz];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".INP").c_str(), "r", stdin);
//    freopen ((file + ".OUT").c_str(), "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + n);

    if (n % 2 == 1) {
        int p = (n + 1) / 2;
        return cout << b[p] - a[p] + 1 << "\n", 0;
    }
    else {
        int p1 = n / 2;
        int p2 = n / 2 + 1;

        double m1 = (b[p1] - a[p1]) / 2.0;
        double m2 = (b[p2] - a[p2]) / 2.0;

        cout << (int)((m2 + m1) / 0.5 + 1) << "\n";
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
