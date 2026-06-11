#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
typedef pair<pll, pll> P;
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

// RangeMinimumQuery
template <typename T>
struct SegTree {
	T init_val;
	int n;
	vector<T> dat;
	
	SegTree(int _n, T init_val) : init_val(init_val) {
		n = 1;
		while (n < _n) n *= 2;
		dat.resize(n * 2 - 1, init_val);
	}
	
	void add(int i, T x) {
		i += n - 1;
		dat[i] += x;
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
		}
	}
	
	void set(int i, T x) {
		dat[i + n - 1] = init_val;
		update(i, x);
	}
	
	// ??¢?´¢??????[a,b), ?????¨????????????k?????????[l,r)
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return init_val;
		if (a <= l && r <= b) return dat[k];
		return query(a, b, k * 2 + 1, l, (l + r) / 2) + query(a, b, k * 2 + 2, (l + r) / 2, r);
	}
	
	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
};

int main() {
	int n, q; cin >> n >> q;
	
	SegTree<ll> sg(n, 0);
	
	while (q--) {
		int com, x, y;
		scanf("%d %d %d", &com, &x, &y);
		if (com == 0) sg.add(x - 1, y);
		else printf("%lld\n", sg.query(x - 1, y));
	}
	return 0;
}