#define _CRT_SECURE_NO_WARNINGS
#define MOD 998244353
#define INF 100000000
//#define MOD 922337203685419LL
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <functional>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define RFOR(i,a,b) for(ll i=(a);i>(b);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n-1,-1)
#define ALL(obj) (obj).begin(), (obj).end()

inline ll madd(ll a, ll b) {
	a %= MOD; b %= MOD;
	return (a + b) % MOD;
}
inline ll msub(ll a, ll b) {
	a %= MOD; b %= MOD;
	a += MOD;
	return (a - b) % MOD;
}
inline ll mmul(ll a, ll b) {
	a %= MOD; b %= MOD;
	return (a * b) % MOD;
}
inline ll mpow(ll a, ll r) {
	long long res = 1;
	while (r > 0) {
		if (r & 1) res = res * a % MOD;
		a = a * a % MOD;
		r >>= 1;
	}
	return res;
}
inline ll minv(ll a) {
	a %= MOD;
	ll b = MOD, u = 0, v = 1;
	while (a) {
		ll t = b / a;
		b -= t * a; swap(a, b);
		u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return u;
}
inline ll mdiv(ll a, ll b) {
	a %= MOD;
	a *= minv(b);
	return a % MOD;
}


//ll fact[]

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
/*
int vs[200001];
int depth[200001];
int id[100001];
vvi G;
int rmqdat[200001];
int rmqind[200001];

void dfs(int v, int p, int d, int& k) {
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	REP(i, G[v].size()) {
		if (G[v][i] != p) {
			dfs(G[v][i], v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
		}
	}
}

void init(int V) {
	int k = 0;
	dfs(0, -1, 0, k);
}

void rmq_init(int* dat, int datlen) {
	int n = 1;
	while (n < datlen) n *= 2;
	REP(i, n * 2) rmqdat[i] = 1000000;
	for (int i = 0, j = n - 1; i < datlen; i++, j++) {
		rmqdat[j] = dat[i];
		rmqind[j] = i;
	}
	RREP(i, n - 1) {
		if (rmqdat[i * 2 + 1] < rmqdat[i * 2 + 2]) {
			rmqdat[i] = rmqdat[i * 2 + 1];
			rmqind[i] = rmqind[i * 2 + 1];
		}
		else {
			rmqdat[i] = rmqdat[i * 2 + 2];
			rmqind[i] = rmqind[i * 2 + 2];
		}
	}
}

pi query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return pi(1000000, -1);
	if (a <= l && r <= b) return pi(rmqdat[k], rmqind[k]);
	else {
		pi pl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		pi pr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		if (pl.first < pr.first) return pl;
		else return pr;
	}
}

int lca(int u, int v, int n) {
	return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1, 0, 0, n * 2 - 1).second];
}
	int n, u, v;
	cin >> n;
	REP(i, n + 1) G.push_back(vi());
	REP(i, n - 1) {
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(n);
	rmq_init(depth, n * 2 - 1);
	int q;
	cin >> q;
	REP(i, q) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
	}
ll fact[200001];
ll fact_inv[200001];
inline ll combi(int a, int b) {
	return mmul(fact[a], mmul(fact_inv[b], fact_inv[a - b]));
}
*/

/*int main() {
	int ttt;
	int arr2[] = { 1,2,1 };
	int arr3[] = { 1,2,1,3,2,3,1 };
	cin >> ttt;
	REP(cas, ttt) {
		ll n, l, r;
		cin >> n >> l >> r;
		if (n == 2) {
			FOR(i, l - 1, r - 1) cout << arr2[i]<<" ";
		}
		else if (n == 3) {
			FOR(i, l - 1, r - 1) cout << arr3[i]<<" ";
		}
		int cnt = r - l + 1;
		if (l == 1) {
			cout << 1 << " ";
			cnt--;
		}
		if (l % 2 == 0) {
			cout << l / 2 << " ";
			l++;
			cnt--;
		}
		if(cnt>0 )
		ll start = l / 2 + 2;
	}
}*/


bool f(ll k, ll n) {
	if (k == 1) return false;
	while (n >= k) {
		if ((n % k) == 0) n /= k;
		else n %= k;
	}
	return n == 1;
}
vector< int64_t > divisor(int64_t n) {
	vector< int64_t > ret;
	for (int64_t i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}
int main() {
	ll n;
	int res = 0;
	cin >> n;
	if (n == 2) {
		cout << 1;
		return 0;
	}
	for (auto i : divisor(n)) {
		if (f(i,n)) res++;
	}
	res += divisor(n - 1).size() - 1;
	cout << res;
	return 0;
}
