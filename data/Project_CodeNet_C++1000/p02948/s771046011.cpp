#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;

	vector<pair<int, int>> p;
	rep(i, 0, n) {
		int a, b; cin >> a >> b;
		p.emplace_back(a, b);
	}
	sort(p.begin(), p.end());

	int j = 0;
	priority_queue<int, vector<int>> pq;
	int ans = 0;
	rep(i, 1, m + 1) {
		// 終了i日前
		while (j < n && p[j].first <= i) pq.push(p[j++].second);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}
