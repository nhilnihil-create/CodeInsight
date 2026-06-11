#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> res;
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
    return b ? gcd(b, a % b) : a;
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
    ll ans = a[0];
    rep(i, n) ans = gcd(ans, a[i]);
    ll asum = accumulate(all(a), 0LL);
    auto f = factorize(asum);
    set<ll> fac;
    rep(i, sz(f)) {
        rep(ii, f[i].second) {
            set<ll> add;
            add.insert(f[i].first);
            for (auto x : fac) add.insert(x * f[i].first);
            for (auto x : add) fac.insert(x);
        }
    }
    map<ll, vector<ll>> surplus;
    for (auto x : fac) {
        surplus[x].resize(n);
        rep(i, n) surplus[x][i] = a[i] % x;
        sort(all(surplus[x]));
    }
    map<ll, vector<ll>> minusdp, plusdp;
    for (auto x : fac) {
        minusdp[x].resize(n);
        rep(i, n) {
            if (i == 0) minusdp[x][i] = surplus[x][i];
            else minusdp[x][i] = minusdp[x][i - 1] + surplus[x][i];
        }
        plusdp[x].resize(n);
        rep(i, n) {
            if (i == 0) plusdp[x][i] = x - surplus[x][i];
            else plusdp[x][i] = plusdp[x][i - 1] + x - surplus[x][i];
        }
    }
    reps(i, 1, n) {
        for (auto x : fac) {
            ll minus = minusdp[x][i - 1], plus = plusdp[x][n - 1] - plusdp[x][i - 1];
            if (abs(minus - plus) % x != 0) continue;
            if (max(minus, plus) > k) continue;
            ans = max(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}
