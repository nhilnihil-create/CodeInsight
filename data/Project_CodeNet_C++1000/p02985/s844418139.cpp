#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

vector<ll> fact, fact_inv;

template <typename T> T mpow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n = n >> 1;
    }
    return ret;
}

void COMinit(ll MAX) {
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = fact_inv[0] = 1;
    rep(i, MAX) {
        fact[i + 1] = fact[i] * (i + 1) % mod;
        fact_inv[i + 1] = mpow(fact[i + 1], mod - 2);
    }
}

ll COM(ll n, ll k) {
    if(n < k || k < 0) return 0;
    return (fact[n] * fact_inv[k] % mod) * fact_inv[n - k] % mod;
}

ll permutation(ll n, ll k) {
    if(n < k || k < 0) return 0;
    return fact[n] * fact_inv[n - k] % mod;
}

ll n, k;
vector<ll> e[100009];
bool visit[100009];

ll dfs(int i) {
    visit[i] = 1;
    ll re;
    if(i == 1)
        re = permutation(k, e[i].size() + 1);
    else
        re = permutation(k - 2, e[i].size() - 1);

    rep(j, e[i].size()) {
        if(visit[e[i][j]]) continue;
        re *= dfs(e[i][j]);
        re %= mod;
    }
    return re;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    COMinit(k);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    cout << dfs(1) << endl;
}