#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const int N = 1000007, inf = 0x3f3f3f3f;

struct segtree {
	vector<int> seg;
	int n;
	segtree(){}
	segtree(int n) {
		seg.assign(n + n + 7, -2 * inf);
		this->n = n;
	}

	int query(int l, int r) {
		int ans = -2 * inf;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l&1) ans = max(ans, seg[l++]);
			if(r&1) ans = max(ans, seg[--r]);
		}
		return ans;
	}

	void update(int p, int val) {
		p += n;
		for(seg[p] = max(seg[p], val); p > 1; p >>= 1) {
			seg[p >> 1] = max(seg[p], seg[p ^ 1]);
		}
	}
};
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);


	int n; cin >> n;
	vector<ii> pts;
	vector<int> Y;
	for(int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		pts.eb(x, y);
		Y.pb(y);
	}

	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	sort(pts.begin(), pts.end());

	segtree up, down;
	up = segtree(n);
	down = segtree(n);

	int ans = -2 * inf;
	// 2 e 4 quadrantes
	for(int i = 0; i < n; ++i) {
		int x, y; tie(x, y) = pts[i];
		int j = lower_bound(Y.begin(), Y.end(), y) - Y.begin();

		// quad 2
		ans = max(ans, up.query(j, n) + x - y);

		// quad 3
		ans = max(ans, down.query(0, j) + x + y);

		// coloca o ponto
		up.update(j, -x + y);
		down.update(j, -x - y);
	}

	up = segtree(n);
	down = segtree(n);
	for(int i = n-1; i >= 0; --i) {
		int x, y; tie(x, y) = pts[i];
		int j = lower_bound(Y.begin(), Y.end(), y) - Y.begin();

		// quad 2
		ans = max(ans, up.query(j, n) - x - y);

		// quad 3
		ans = max(ans, down.query(0, j) - x + y);

		// coloca o ponto
		up.update(j, x + y);
		down.update(j, x - y);
	}
	cout << ans << endl;
}