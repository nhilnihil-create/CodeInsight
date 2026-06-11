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

const int siz = 3e2 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "2";

int n, k;
int a[siz];
int f[siz][siz][siz];

int dp(int pos, int cnt, int prv) {
    if (pos == n + 1) {
        if (cnt == k) {
            return 0;
        }
        return MAXX;
    }

    int &res = f[pos][cnt][prv];
    if (res != -1) {
        return res;
    }

    res = dp(pos + 1, cnt, pos) + max(a[pos] - a[prv], 0LL);

    if (cnt < k) {
        res = min(res, dp(pos + 1, cnt + 1, prv));
    }

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(f, -1, sizeof(f));

    cout << dp(1, 0, 0) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
