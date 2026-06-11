#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m);
	rep(i, n) {
		int p, q;
		cin >> p >> q;
		if (p <= m) a[p - 1].push_back(q);
	}
	priority_queue<int> que;
	int ans = 0;
	rep(i, m) {
		for (auto p : a[i]) que.push(p);
		if (!que.empty()) {
			ans += que.top();
			que.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}