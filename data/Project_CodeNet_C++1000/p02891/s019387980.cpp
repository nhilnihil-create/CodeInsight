#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    string s;
    int k;
    cin >> s >> k;

    vi a{1};
    for (int i = 1; i < sz(s); i++) {
        if (s[i - 1] == s[i]) a.back()++;
        else a.pb(1);
    }

    if (sz(a) == 1) {
        cout << (ll)a[0] * k / 2;
        return 0;
    }

    ll cnt = 0;
    for (int i : a) cnt += i / 2ll * k;
    if (s[0] == s.back()) {
        for (int i : {a[0], a.back()}) cnt -= i / 2ll * (k - 1);
        cnt += (a[0] + a.back()) / 2ll * (k - 1);
    }
    cout << cnt;

    return 0;
}
