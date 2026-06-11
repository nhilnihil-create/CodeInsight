#pragma GCC optimize("Ofast", "unroll-loops")

// #define TEST

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll mod = 1000000007LL;

ll fact(ll k, int sgn = 0) {
	static vector<ll> fac(2, 1LL);
	static vector<ll> inv(2, 1LL);
	static vector<ll> finv(2, 1LL);
	static ll nx = 2LL;
	while (nx <= k) {
		fac.push_back(fac[nx - 1] * nx % mod);
		inv.push_back(mod - inv[mod % nx] * (mod / nx) % mod);
		finv.push_back(finv[nx - 1] * inv[nx] % mod);
		++nx;
	}
	if (sgn == 0)
		return fac[k];
	return finv[k];
}

ll comb(ll a, ll b) {
	if (b < 0 || b > a) return 0;
	return fact(a) * fact(b, 1) % mod * fact(a - b, 1) % mod;
}

int N, K;
vector<vector<int>> g;

void input(void){
    cin >> N >> K;
    g.resize(N);
    for (int i = 0; i < N - 1; ++i){
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

vector<int> cnt_children;

void dfs(int s = 0, int p = -1){
    int cnt = 0;
    for (auto c : g[s])
        if (c != p){
            ++cnt; dfs(c, s);
        }
    cnt_children[s] = cnt;
}

ll solve(void){
    ll res = K;
    cnt_children.resize(N);
    dfs();
#ifdef TEST
    cout << "-----cnt_children-----" << endl;
    for (auto ci : cnt_children)
        cout << ci << " ";
    cout << endl;
#endif
    for (int i = 0; i < N; ++i){
        int c = cnt_children[i];
        ll tmp = fact(c);
        tmp *= comb(K - (i == 0 ? 1LL : 2LL), c);
        tmp %= mod;
        res = (res * tmp) % mod;
    }
    return res;
}

int main(void){
    input();
    cout << solve() << endl;
    return 0;
}