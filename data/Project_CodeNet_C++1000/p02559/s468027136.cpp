#include <atcoder/convolution>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>
#include <atcoder/lazysegtree>
#include <atcoder/math>
#include <atcoder/maxflow>
#include <atcoder/mincostflow>
#include <atcoder/modint>
#include <atcoder/scc>
#include <atcoder/segtree>
#include <atcoder/string>
#include <atcoder/twosat>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using namespace internal;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)

int main() {
	ll n, q;
	cin >> n >> q;
	fenwick_tree<ll> f(n);
	rep(i, n) {
		ll a;
		cin >> a;
		f.add(i,a);
	}
	ll ans;
	rep(i, q) {
		int op;
		cin >> op;
		if (op == 0) {
			ll p, x;
			cin >> p >> x;
			f.add(p,x);
		}
		else if (op == 1) {
			ll l, r;
			cin >> l >> r;
			ans = f.sum(l, r);
			cout << ans << endl;
		}
	}
}