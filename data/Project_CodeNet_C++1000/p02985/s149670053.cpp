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

struct BinomialCoefficient  {
    BinomialCoefficient() {
        
    }
    
    BinomialCoefficient(int n) : fac(n + 2), finv(n + 2), inv(n + 2) {
        initialize(n, false);
    }
    
    void initialize(int n, bool resize = true) {
        if (resize) {
            fac.resize(n + 2);
            finv.resize(n + 2);
            inv.resize(n + 2);
        }
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    
    ll factorial(int n) {
        return fac[n];
    }
    
    ll combination(int n, int r) {
        if ((n < r) || (n < 0) || (r < 0)) return 0;
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
    
    ll permutation(int n, int r) {
        if ((n < r) || (n < 0) || (r < 0)) return 0;
        return fac[n] * finv[n - r] % mod;
    }
    
private:
    int mod = 1e9 + 7;
    vector<ll> fac, finv, inv;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll mod = 1e9 + 7;
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> g(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> seen(n, false);
    queue<ll> q;
    q.push(0);
    ll ans = k;
    BinomialCoefficient bc(max(n, k));
    while(!q.empty()) {
        ll v = q.front(); q.pop();
        seen[v] = true;
        set<ll> s;
        for(auto u : g[v]) {
            if (seen[u]) continue;
            s.insert(u);
        }
        if (sz(s) == 0) continue;
        if (v == 0) ans = (ans * bc.permutation(k - 1, sz(s))) % mod;
        else ans = (ans * bc.permutation(k - 2, sz(s))) % mod;
        for(auto x : s) q.push(x);
    }
    cout << ans << endl;
    return 0;
}
