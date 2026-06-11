#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define int long long
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define pb push_back
#define eb emplace_back
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

int n, ans;

void solve() {
	cin >> n;

	FOR (i, 1, n - 1) {
		int u, v; cin >> u >> v;

		if (u > v) swap(u, v);

		// edges
		ans -= u * (n - v + 1);
	}

	// vertices

	FOR (i, 1, n) {
		ans += i * (n - i + 1);
	}

	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) 
		solve();
	return 0;
}