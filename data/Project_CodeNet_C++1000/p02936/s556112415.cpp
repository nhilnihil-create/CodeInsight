#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N_MAX = 200000;

int main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int c[N_MAX] = {0};
	for (int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		p--;
		c[p] += x;
	}
	struct State
	{
		int v, parent, count;
	};
	stack<State> s;
	s.push({0, -1, c[0]});
	int ans[N_MAX];
	while (!s.empty()) {
		auto cur = s.top(); s.pop();
		ans[cur.v] = cur.count;
		for (int nv : g[cur.v]) {
			if (nv == cur.parent) continue;
			s.push({nv, cur.v, cur.count+c[nv]});
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i != n-1) cout << ' ';
		else cout << endl;
	}
	return 0;
}