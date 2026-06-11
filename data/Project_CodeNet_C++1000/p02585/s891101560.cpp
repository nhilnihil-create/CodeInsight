#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SZ(x) (int)((x).size())
#define xx first
#define yy second
#define pii pair<int, int>

const int N = 5e3 + 1;
const ll oo = 1e18;

int c[N], p[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i], --p[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll ans = -oo;
    for (int i = 0; i < n; i++) {
        vector<ll> prfx(1, 0);
        for (int j = p[i]; j != i; j = p[j])
            prfx.push_back(c[j]);
        prfx.push_back(c[i]);
        for (int j = 1; j < SZ(prfx); j++)
            prfx[j] += prfx[j - 1];

        ll score = -oo;
        int m = SZ(prfx) - 1;
        ll mx = -oo, mxI = 0;
        for (int j = 1; j <= m; j++) 
            mx = max(mx, prfx[j]);
        for (int j = 1; j <= m; j++)
            if (!mxI && prfx[j] == mx) 
                mxI = j;

        if (k >= m) {
            if (prfx[m] > 0) {
                int q = k / m, r = k % m;
                if (mxI <= r)
                    score = q * prfx[m] + mx;
                else {
                    ll pmx = 0;
                    for (int j = 1; j <= r; j++)
                        pmx = max(pmx, prfx[j]);
                    score = max(q * prfx[m] + pmx, max(q - 1, 0) * prfx[m] + mx);
                }
            }
            else
                score = mx;
        }
        else 
            for (int j = 1; j <= k; j++)
                score = max(score, prfx[j]);
        ans = max(ans, score);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
