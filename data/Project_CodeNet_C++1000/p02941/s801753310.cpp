#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//https://atcoder.jp/contests/agc037/tasks/agc037_c

const int nm = 2e5;
int n, a[nm], b[nm];
ll ans = 0;

priority_queue<pair<int, int>> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i) {
		if (b[i] < a[i]) {
			cout << -1 << endl;
			return 0;
		}
		if (b[i] != a[i])
			q.emplace(b[i], i);
	}
	while (!q.empty()) {
		int i = q.top().second;
		q.pop();

		int t = (b[i] - a[i]) / (b[(i + n - 1) % n] + b[(i + 1) % n]);
		if (!t) {
			cout << -1 << endl;
			return 0;
		}
		ans += t;
		b[i] -= (b[(i + n - 1) % n] + b[(i + 1) % n]) * t;

		if (b[i] != a[i])
			q.emplace(b[i], i);
	}
	cout << ans << endl;
}
