#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vii a(n);
    rep(i, n) cin >> a[i].fi >> a[i].se;

    int l, r;
    vi t(n);

    sort(all(a));
    l = a[n / 2].fi;
    if (~n & 1) l += a[n / 2 - 1].fi;

    sort(all(a), [](ii& a, ii& b) {
        if (a.se < b.se) return true;
        return false;
    });
    r = a[n / 2].se;
    if (~n & 1) r += a[n / 2 - 1].se;

    cout << r - l + 1;

    return 0;
}
