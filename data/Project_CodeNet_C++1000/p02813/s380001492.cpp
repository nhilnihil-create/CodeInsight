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
    int p[n], q[n];
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> q[i];
    int r[n];
    rep(i, 0, n) r[i] = i + 1;
    int cnt = 0, ans = 0;
    do {
        cnt++;
        bool cp = 1, cq = 1;
        rep(i, 0, n) {
            if (p[i] != r[i]) cp = 0;
            if (q[i] != r[i]) cq = 0;
        }
        if (cp) ans -= cnt;
        if (cq) ans += cnt;
    } while (next_permutation(r, r + n));
    cout << abs(ans) << "\n";
}