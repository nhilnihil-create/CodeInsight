#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	long long n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	long long ans = 1;
	struct State
	{
		long long v, parent, x;
	};
	queue<State> q;
	q.push({0, -1, k});
	while (!q.empty()) {
		State cur = q.front(); q.pop();
		ans = mod(ans * cur.x);
		int x = k - 2;
		if (cur.v == 0) x++;
		for (int nv : g[cur.v]) {
			if (nv == cur.parent) continue;
			q.push({nv, cur.v, x});
			x--;
		}
	}
	cout << ans << endl;
	return 0;
}