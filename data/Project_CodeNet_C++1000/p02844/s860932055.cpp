#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i, 0, 1000) {
        string t;
        int x = i;
        rep(j, 0, 3) {
            t += '0' + x % 10;
            x /= 10;
        }
        int ti = 0;
        rep(j, 0, n) {
            if (s[j] == t[ti]) {
                ti++;
                if (ti == 3) break;
            }
        }
        if (ti == 3) ans++;
    }
    cout << ans << "\n";
}