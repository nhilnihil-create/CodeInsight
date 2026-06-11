#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int siz = 3e3 + 10;
const int SIZ = 3e3 + 10;
const int mod = 998244353;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "2";

int n, s;
int a[siz];
int f[siz][SIZ];

int dp(int pos, int sum) {
    if (pos == n + 1) {
        return (sum == s);
    }

    int &res = f[pos][sum];
    if (res != -1) {
        return res;
    }

    res = dp(pos + 1, sum); /// only put to N

    (res += dp(pos + 1, sum)) %= mod; /// do not put

    if (sum + a[pos] <= s)
        (res += dp(pos + 1, sum + a[pos])) %= mod; /// put to both N and T

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(f, -1, sizeof(f));

    cout << dp(1, 0) << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
