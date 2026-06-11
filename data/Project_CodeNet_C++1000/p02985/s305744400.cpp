#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll COMinv(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return finv[n] * (fac[k] * fac[n - k] % MOD) % MOD;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

using Graph = vector<vector<int>>;
ll N, K;
ll ans;

void dfs(const Graph& graph, int v, int p) {
	//行きがけ処理
	ll csize = graph[v].size() - 1;
	if (p == -1){
		csize++;
		if (K-1 < csize){
			ans = 0;
		} else {
			ll tmp = (fac[K-1] * finv[K - 1 - csize]) % MOD;
			ans = (ans * tmp) % MOD;
		}
	} else if (csize == 0){
	} else {
		if (K-2 < csize){
			ans = 0;
		} else {
			ll tmp = (fac[K-2] * finv[K - 2 - csize]) % MOD;
			ans = (ans * tmp) % MOD;
		}
	}
	for (auto nv : graph[v]){
		if (nv == p) continue;
		dfs(graph, nv, v);
	}
}

int main() {
	cin >> N >> K;

	Graph graph(N);
	for (int ii = 0; ii < N-1; ++ii){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	COMinit();

	int root = 0;
	ans = K;
	dfs(graph, /*v=*/root, /*p=*/-1);
	
	cout << ans << "\n";

	return 0;
}
