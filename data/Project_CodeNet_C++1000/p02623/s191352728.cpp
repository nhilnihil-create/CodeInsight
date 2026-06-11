#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; ll k; cin >> n >> m >> k;
	vector<ll> accum_a(n + 1, 0), accum_b(m + 1, 0);
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		accum_a[i + 1] += a;
		accum_a[i + 1] += accum_a[i];
	}
	for (int i = 0; i < m; i++) {
		ll b; cin >> b;
		accum_b[i + 1] += b;
		accum_b[i + 1] += accum_b[i];
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll tmpAns = i;
		if (k < accum_a[i]) continue;
		ll diff = k - accum_a[i];
		auto it = upper_bound(accum_b.begin(), accum_b.end(), diff);
		tmpAns += it - accum_b.begin() - 1;
		ans = max(ans, tmpAns);
	}
	cout << ans << endl;
    return 0;
}