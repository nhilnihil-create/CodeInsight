#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MAX (ll)1e6+1    //nCrのnの最大値+1

ll fac[MAX], inv[MAX], finv[MAX];

void COMinit(ll mod) {
    fac[0] = 1, finv[0] = 1;
    fac[1] = 1, inv[1] = 1, finv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - (inv[mod % i] * (mod/i) % mod) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll COM(ll n, ll k, ll mod) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * finv[k] % mod * finv[n-k] % mod;
}

ll dfs(int k, vector<vector<int> > &G, int s, int p, ll mod) {
    ll ans = 1, cnt = 0;
    for (auto u: G[s]) {
        if (u == p)
            continue;
        cnt++;
    }
    ll l = k-1-((p >= 0) ? 1 : 0);
    if (l < cnt)
        return 0;
        
    ans *= fac[l] * finv[l-cnt] % mod;
    ans %= mod;
    for (auto u: G[s]) {
        if (u == p)
            continue;
        ans = ans * dfs(k, G, u, s, mod) % mod;
    }
    return ans;
}

int main() {
    ll n, k, mod = 1e9+7;    cin >> n >> k;

    if (n == 1 && k == 1) {
        cout << 1 << endl;
        return 0;
    }
    else if (k == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int> > G(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;   cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    COMinit(mod);

    cout << k * dfs(k, G, 0, -1, mod) % mod << endl;
    return 0;
}