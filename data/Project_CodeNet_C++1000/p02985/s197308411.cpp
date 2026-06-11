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
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int n, k;
vector<int> g[100005];

int modPow(long long a, long long n, long long p) {//0でバグる
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
	return res;
}

ll perm(ll a, ll b) {
	if (a < 0 || a < b) return 0;
	return comb(a, b) * fact(b) % mod;
}

ll ans;

void dfs(int s, int p = -1) {
	for (auto& c : g[s]) {
		if (c == p) continue;
		dfs(c, s);
	}
	int nk = (p == -1) ? k : k - 2;
	int nc = (p == -1) ? g[s].size() + 1 : g[s].size() - 1;
	(ans *= perm(nk, nc)) %= mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	ans = 1;
	dfs(0);
	cout << ans << endl;
	return 0;
}