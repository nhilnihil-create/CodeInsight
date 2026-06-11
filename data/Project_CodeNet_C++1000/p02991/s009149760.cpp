#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define DEC(i, a, b) for (int i = (int)a; i >= (int)b; i--)
typedef pair<int, int> pi;
#define f first
#define s second

int n, m, a, b, dist[100050][3], st, t;
vector<int> adj[100050];
queue<pi> q;

int main() {
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	cin >> st >> t;
	q.push(pi(st, 0));
	memset(dist, -1, sizeof dist);
	dist[st][0] = 0;
	while (!q.empty()) {
		pi x = q.front(); q.pop();
		int nd = (x.s + 1) % 3;
		for (auto it:adj[x.f]) {
			if (dist[it][nd] != -1) continue;
			dist[it][nd] = dist[x.f][x.s] + (x.s == 0);
			q.push(pi(it, nd));
		}
	}
	cout << dist[t][0];
}

