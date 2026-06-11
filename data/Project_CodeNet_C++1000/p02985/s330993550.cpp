//
// Created by Hideaki Imamura on 2020-03-25.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
const ll mod = 1000000007;

ll fact[200000];
ll invfact[200000];

inline ll take_mod(ll a) {
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b) {
    return take_mod(a + b);
}

inline ll sub(ll a, ll b) {
    return take_mod(a - b);
}

inline ll mul(ll a, ll b) {
    return take_mod(a * b);
}

inline ll mod_pow(ll x, ll n) {
    ll res = 1LL;
    while (n > 0) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x) {
    return mod_pow(x, mod - 2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k) {
    return mul(mul(fact[n], invfact[n - k]), invfact[k]);
}

ll N, K;
vector<vector<ll>> G;

ll dfs(ll now, ll from) {
    ll n_color = from == -1 ? K - 1 : K - 2;
    if (K < G[now].size()) return 0;
    ll n_case = 1;
    for (auto v : G[now]) {
        if (v == from) continue;
        n_case = mul(n_case, n_color);
        n_color--;
    }
    for (auto v : G[now]) {
        if (v == from) continue;
        n_case = mul(n_case, dfs(v, now));
    }
    return n_case;
}

int main() {
    cin >> N >> K;
    G.assign(N, vector<ll>());
    for (int i = 0; i < N - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << mul(K, dfs(0, -1)) << endl;
    return 0;
}