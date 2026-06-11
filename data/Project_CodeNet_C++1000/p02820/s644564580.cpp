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
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    int ans = 0;
    rep (i, 0, n) {
        if (i < k) {
            if (t[i] == 'r') {
                ans += p;
            } else if (t[i] == 's') {
                ans += r;
            } else {
                ans += s;
            }
        } else {
            if (t[i] != t[i - k]) {
                if (t[i] == 'r') {
                    ans += p;
                } else if (t[i] == 's') {
                    ans += r;
                } else {
                    ans += s;
                }
            } else {
                t[i] = '.';
            }
        }
        // cout << ans << "\n";
    }
    cout << ans << "\n";
}