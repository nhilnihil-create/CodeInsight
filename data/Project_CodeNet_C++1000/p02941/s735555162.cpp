#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;
int const MAX = 105;


int n, a[N], d[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	priority_queue < pair < int, int > > que;
	for (int i = 1; i <= n; i++) {
		que.push(make_pair(a[i], i));
	}
	a[0] = a[n];
	a[n + 1] = a[1];
	long long ans = 0;
	while (!que.empty()) {
		pair < int, int > p = que.top(); que.pop();
		int val = p.first;
		int id = p.second;
		int pre = a[id - 1];
		int nxt = a[id + 1];
		if (a[id] == d[id]) {
			continue;
		}
		if (a[id] - d[id] < pre + nxt) {
			continue;
		}
		ans += (a[id] - d[id]) / (pre + nxt);
		a[id] = (a[id] - d[id]) % (pre + nxt) + d[id];

		a[0] = a[n]; a[n + 1] = a[1];
		que.push(make_pair(a[id], id));
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] != d[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << ans << endl;
}