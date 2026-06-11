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
    cin >> n;
    int a[n], b[n], c[n - 1];
    rep (i, 0, n) {
        cin >> a[i];
        a[i]--;
    }
    rep (i, 0, n) cin >> b[i];
    rep (i, 0, n - 1) cin >> c[i];
    int ans = 0;
    rep (i, 0, n) {
        ans += b[a[i]];
        if (i > 0) {
            if (a[i] == a[i - 1] + 1) {
                ans += c[a[i - 1]];
            }
        }
    }
    cout << ans << "\n";
}