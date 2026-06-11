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

vector<ll> ft;

ll query(int i) {
    ll ret = 0;
    for (; ~i; i = (i & (i + 1)) - 1) ret += ft[i];
    return ret;
}

void update(int i, ll d) {
    for (; i < sz(ft); i |= i + 1) ft[i] += d;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, a;
    cin >> n >> d >> a;
    map<int, ii> mon;
    rep(i, n) {
        int x, h;
        cin >> x >> h;
        mon[x].fi = h;
    }

    ft.resize(n + 1);

    int idx = 0;
    for (auto& i : mon) i.se.se = idx++;

    idx = -1;
    ll cnt = 0;
    for (auto& i : mon) {
        idx++;

        ll cdmg = query(idx), hp = i.se.fi - cdmg;
        if (hp <= 0) continue;

        int x = min(1ll << 30, i.fi + 2ll * d);
        int idxReach = (--mon.upper_bound(x))->se.se;
        int atk = (hp + a - 1) / a;
        cnt += atk;

        int dmg = min(1ll << 30, (ll)atk * a);
        update(0, dmg);
        update(idxReach + 1, -dmg);
    }
    cout << cnt;

    return 0;
}
