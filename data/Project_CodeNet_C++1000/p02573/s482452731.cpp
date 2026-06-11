#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> P;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>

struct UnionFind {
public:
	vector <ll> par; // 
	vector <ll> siz; // 

	UnionFind() {}

	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}

	ll root(ll x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}

	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	bool issame(ll x, ll y) {
		return root(x) == root(y);
	}

	ll size(ll x) {
		return siz[root(x)];
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	UnionFind uf(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf.merge(a, b);
	}
	ll low = 0;
	rep(i, n) {
		chmax(low, uf.size(i));
	}
	cout << low << endl;
	return 0;
}
