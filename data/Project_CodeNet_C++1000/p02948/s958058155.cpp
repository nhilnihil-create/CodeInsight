#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m);
	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		if (p <= m) {
			a[m - p].emplace_back(q);
		}
	}

	priority_queue<int> q;
	int ans = 0;
	for (int i = m - 1; i >= 0; i--) {
		for (auto & j : a[i]) {
			q.push(j);
		}

		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;

	return 0;
}