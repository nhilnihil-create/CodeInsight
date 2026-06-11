#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

ll modPow(long long a, long long n, long long p) {//0でバグる
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
	long long t = modPow(a, n / 2, p);
	return (t * t) % p;
}

ll comb(ll n, ll p) {
	if (p * 2 > n) p = n - p;
	if (p > n - p) p = n - p;
	ll a = 1, b = 1;
	rrep(i, p + 1) {
		a = (a * (n - i + 1)) % mod;
		b = (b * i) % mod;
	}
	return a * (modPow(b, mod - 2, mod)) % mod;
}

ll fact(ll a) {
	ll res = 1;
	for (int i = 1; i <= a; ++i) (res *= i) %= mod;
	return res % mod;
}

ll perm(ll a, ll b) {
	if (a < 0 || a < b) return 0;
	return comb(a, b) * fact(b) % mod;
}

ll n, k;
vector<int> g[100005];
ll ans;
bool vi[100005];

void dfs(int v, int p = -1) {
	for (auto& c : g[v]) {
		if (c == p) continue;
		dfs(c, v);
	}
	ll pp = 0;
	if (v == 0) pp += perm(k - 1, g[v].size());
	else pp += perm(k - 2, g[v].size() - 1);
	(ans *= pp) %= mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans = k;
	dfs(0);
	printf("%lld\n", ans );
	return 0;
}
