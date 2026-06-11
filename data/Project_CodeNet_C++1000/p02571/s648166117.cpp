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

    string s, t;
    cin >> s >> t;

    int n = sz(s); s = ' ' + s;
    int m = sz(t); t = ' ' + t;

    int ans = maxx;
    for (int i = 1; i <= n - m + 1; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (s[i + j - 1] != t[j]) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }

    cout << ans << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
