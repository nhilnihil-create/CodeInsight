#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define mod 1000000007

struct UnionFind {

	vector<ll> par;
	UnionFind(ll size) {
		par = vector<ll>(size, -1);
	}

	ll root(ll x) {
		if (par[x] < 0)return x;
		return par[x] = root(par[x]);
	}


	bool unit(ll a, ll b) {
		a = root(a);
		b = root(b);
		if (a == b)return false;
		if (-par[a] < -par[b])swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	}

};


int main() {
	ll n, m;
	cin >> n >> m;
	struct UnionFind uf(n);
	
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--;	b--;
		uf.unit(a, b);
	}
	set<ll> ans;
	rep(i, n) {
		ans.insert(uf.root(i));
	}
	cout << ans.size() - 1 << endl;

	return 0;
}