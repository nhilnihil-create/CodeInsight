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
 
int a[siz], b[siz];
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
 
        a[i] += a[i - 1];
    }
 
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
 
        b[i] += b[i - 1];
    }
 
    int ans = 0;
    for (int i = 0, j = m; i <= n; i++) {
        if (k - a[i] < 0) {
            break;
        }
 
        while (a[i] + b[j] > k) {
            j--;
        }
 
        ans = max(ans, i + j);
    }
 
    cout << ans << "\n";
 
//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
 
    return 0;
}