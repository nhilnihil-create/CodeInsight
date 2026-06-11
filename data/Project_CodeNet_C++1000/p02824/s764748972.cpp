#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, m, v, p, ans;
ll a[N], b[N];

bool cmp(ll a, ll b) {
    return a > b;
}

bool chk(ll lim) {
    rep(i, 1, n) a[i] = b[i];
    ll vv = v, pos;
    pos = lim;
    while (pos <= n && vv) {
        a[pos] += m; --vv, ++pos;
    }
    pos = 1;
    while (pos <= p - 1 && vv) {
        a[pos] += m; --vv, ++pos;
    }
    if (!vv) {
        return a[lim] >= a[p];
    }
    ll rest = 1ll * vv * m;
    rep(i, p, lim - 1) {
        ll t = a[lim] - a[i];
        if (t < 0) return 0;
        t = min(t, rest);
        rest -= t;
        if (!rest) return 1;
    } return 0;
}

int main() {
    cin >> n >> m >> v >> p;
    rep(i, 1, n) scanf("%lld", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1, cmp);
    ll l = p, r = n;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (chk(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}
