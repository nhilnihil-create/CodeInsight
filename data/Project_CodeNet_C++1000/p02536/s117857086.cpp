#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
	int n, m; cin >> n >> m;
	dsu uf(n);
	while(m--) {
		int a, b; cin >> a >> b;
		--a, --b;
		uf.merge(a, b);
	}
	int ans = -1;
	for(int i = 0; i < n; ++i) {
		if(i == uf.leader(i)) ++ans;
	}
	cout << ans << '\n';
	return 0;
}
