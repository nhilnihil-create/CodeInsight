#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

vector<pair<ll, ll>> factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll i = 2; (i * i) <= n; i++) {
        if (n % i) continue;
        res.emplace_back(i, 0);
        while((n % i) == 0) {
            n /= i;
            res.back().second++;
        }
    }
    if (n != 1) res.emplace_back(n, 1);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    ll suma = accumulate(all(a), 0LL);
    auto fac = factorize(suma);
    set<ll> div;
    div.insert(1);
    rep(i, sz(fac)) {
        rep(j, fac[i].second) {
            set<ll> add;
            for(auto x : div) add.insert(x * fac[i].first);
            for(auto x : add) div.insert(x);
        }
    }
    ll ans = a[0];
    rep(i, n) ans = __gcd(ans, a[i]);
    for(auto x : div) {
        vector<ll> moda(n);
        rep(i, n) moda[i] = a[i] % x;
        sort(all(moda));
        vector<ll> ldp(n + 1, 0), rdp(n + 1, 0);
        rep(i, n) ldp[i + 1] = ldp[i] + moda[i];
        rep(i, n) rdp[i + 1] = rdp[i] + (x - moda[i]) % x;
        bool f = false;
        reps(i, 1, n) {
            ll left = ldp[i];
            ll right = rdp[n] - rdp[i];
            if ((abs(left - right) % x == 0) && (max(left, right) <= k)) {
                f = true;
                break;
            }
        }
        if (f) ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
