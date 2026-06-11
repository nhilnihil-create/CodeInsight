#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n;
int m;
vector<int> g[N];
int d[N][3];

signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int v;
		int u;
		cin >> v >> u;
		--v;
		--u;
		g[v].push_back(u);
	}
	queue<int> q;
	fill_n(d[0], 3 * N, INF);
	int s;
	int t;
	cin >> s >> t;
	--s;
	--t;
	d[s][0] = 0;
	q.push(s);
	while (q.size()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
			if (d[u][1] > d[v][0]) {
				d[u][1] = d[v][0];
				q.push(u);
			}
			if (d[u][2] > d[v][1]) {
				d[u][2] = d[v][1];
				q.push(u);
			}
			if (d[u][0] > d[v][2] + 1) {
				d[u][0] = d[v][2] + 1;
				q.push(u);
			}
		}
	}
	int ans = d[t][0];
	if (ans < INF) {
		cout << ans << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
