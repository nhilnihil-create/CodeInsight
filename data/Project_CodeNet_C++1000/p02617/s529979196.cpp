#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ll ans = n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		ans += 1LL * (i + 1) * (n - i);
		ans -= 1LL * u * (n - v + 1);
	}
	cout << ans << '\n';
}