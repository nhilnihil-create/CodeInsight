#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int n, m;

int main() {
	cin >> n >> m;
	dsu d(n);
	int ans = n - 1;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		if (!d.same(a, b)) {
			--ans;
			d.merge(a, b);
		}
	}
	cout<<ans<<endl;

}
