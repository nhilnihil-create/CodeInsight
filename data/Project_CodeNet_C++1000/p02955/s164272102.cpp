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

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll suma = accumulate(all(a), 0LL);
    vector<pair<ll, ll>> fac = factorize(suma);
    set<ll> div;
    div.insert(1);
    rep(i, sz(fac)) {
        rep(ii, fac[i].second) {
            set<ll> add;
            for(auto x : div) add.insert(x * fac[i].first);
            for(auto x : add) div.insert(x);
        }
    }
    map<ll, vector<ll>> surplus, dp;
    for(auto x : div) {
        surplus[x].resize(n);
        rep(i, n) surplus[x][i] = a[i] % x;
        sort(all(surplus[x]));
        dp[x].resize(n + 1, 0);
        rep(i, n) dp[x][i + 1] = dp[x][i] + surplus[x][i];
    }
    ll ans = a[0];
    reps(i, 1, n) ans = gcd(ans, a[i]);
    reps(i, 1, n) {
        for(auto x : div) {
            ll minus = dp[x][i];
            ll plus = (n - i) * x - (dp[x][n] - dp[x][i]);
            if (abs(minus - plus) % x != 0) continue;
            if (max(minus, plus) <= k) ans = max(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}
