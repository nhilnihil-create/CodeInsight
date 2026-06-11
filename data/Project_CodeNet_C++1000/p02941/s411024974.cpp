#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

int in (int v) {
	if (v == 0) return n;
	if (v == n+1) return 1;
	if (v == -1) return n-1;
	if (v == n+2) return 2;
	return v;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vector <int> a(n+1), b(n+1);
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	priority_queue <pair<int, int>> bfs;
	for (int i=1; i<=n; i++) {
		if (b[i] > b[in(i-1)]+b[in(i+1)] && b[i] > a[i]) {
			bfs.push({b[i], i});
		}
	}
	ll ans = 0;
	while (!bfs.empty()) {
		int v = bfs.top().second;
		bfs.pop();
		int cnt = (b[v]-a[v])/(b[in(v-1)]+b[in(v+1)]);
		ans += cnt;
		b[v] -= cnt*(b[in(v-1)]+b[in(v+1)]);
		if (b[in(v-1)] > b[in(v-2)]+b[v] && b[in(v-1)] > a[in(v-1)]) {
			bfs.push({b[in(v-1)], in(v-1)});
		}
		if (b[in(v+1)] > b[in(v+2)]+b[v] && b[in(v+1)] > a[in(v+1)]) {
			bfs.push({b[in(v+1)], in(v+1)});
		}
	}
	for (int i=1; i<=n; i++) {
		if (b[i] != a[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
