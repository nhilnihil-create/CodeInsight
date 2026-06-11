#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n, k; cin >> n >> k;
    vi p(n + 1), c(n + 1);
    FOR(i, 1, n) cin >> p[i];
    FOR(i, 1, n) cin >> c[i];
    ll ans = -INF;
    FOR(i, 1, n) {
        vll cyc(1);
        ll sum = 0, mx = -INF;
        int cur = i;
        do {
            cur = p[cur];
            sum += c[cur], mx = max(sum, mx);
            if (sz(cyc) == 1) cyc.pb(sum);
            else cyc.pb(max(cyc[sz(cyc) - 1], sum));
        } while (cur != i);
        int len = sz(cyc) - 1;
        // cerr << len << ' ' << sum << endl;
        if (k >= 2 * len) ans = max(ans, sum * (k / len - 1) + cyc[len]);
        if (k >= len) ans = max(ans, sum * (k / len) + cyc[k % len]);
        ans = max(ans, cyc[min(len, k)]);
    }
    cout << ans << endl;
}