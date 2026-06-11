#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

vector<int> g[100005];
int dist[100005][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
	}
	int s, t;
	cin >> s >> t;
	s--; t--;
	memset(dist, -1, sizeof(dist));
	queue<P> que;
	que.emplace(s, 0);
	dist[s][0] = 0;
	while (que.size()) {
		int u = que.front().first;
		int v = que.front().second;
		que.pop();
		for (auto& c : g[u]) {
			int nv = (v + 1) % 3;
			if (dist[c][nv] != -1) continue;
			dist[c][nv] = dist[u][v] + 1;
			que.emplace(c, nv);
		}
	}
	if (dist[t][0] == -1) cout << -1 << endl;
	else cout << dist[t][0] / 3 << endl;
	return 0;
}