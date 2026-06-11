#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Max = 100006;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, a[Max];
	set <ll> bad[Max];
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	ll l, r;
	for (int i=1; i<=m; i++) {
		cin >> l >> r;
		if (a[r] >= a[l]) bad[l].insert(1);
		if (a[l] >= a[r]) bad[r].insert(1);
	}
	ll ans = 0;
	for (int i=1; i<=n; i++) if (!bad[i].size()) {
		ans++;
	}
	cout << ans;
	return 0;
}