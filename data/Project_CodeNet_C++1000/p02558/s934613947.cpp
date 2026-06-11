#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>

int main() {
	int n, q;
	cin >> n >> q;
	dsu d(n);
	rep(i,q) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) d.merge(u, v);
		else cout << d.same(u, v) << endl;
	}
	return 0;
}