#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int siz = 2e5 + 10;
const int SIZ = 2e3 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e12;
const string file = "2";

int f[SIZ];

int dp(int rem) {
    if (rem == 0) {
        return 1;
    }

    int &res = f[rem];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (int i = 3; i <= rem; i++) {
        (res += dp(rem - i)) %= mod;
    }

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    int s;
    cin >> s;

    memset(f, -1, sizeof(f));

    cout << dp(s) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
