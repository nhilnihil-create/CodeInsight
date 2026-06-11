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
    int a[n], b[n];
    rep (i, 0, n) cin >> a[i] >> b[i];
    sort (a, a + n);
    sort (b, b + n);
    int ans;
    if (n % 2 == 0) {
        ans = ((b[n / 2] + b[n / 2 - 1]) - (a[n / 2] + a[n / 2 - 1])) + 1;
    } else {
        ans = b[n / 2] - a[n / 2] + 1;
    }
    cout << ans << "\n";
}
