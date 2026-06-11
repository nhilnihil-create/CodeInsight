#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<ll> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<ll> nextToPointMaxh(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		--a;
		--b;
		nextToPointMaxh[a] = max(nextToPointMaxh[a], h[b]);
		nextToPointMaxh[b] = max(nextToPointMaxh[b], h[a]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (nextToPointMaxh[i] < h[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}