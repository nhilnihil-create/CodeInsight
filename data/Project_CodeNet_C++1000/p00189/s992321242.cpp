#include <list>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#define INF (1LL << 60)
using namespace std;
bool used[10]; long long dist[10];
void dijkstra(int V, int E, int s, vector<pair<int, long long> > X[]) {
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > Q;
	for (int i = 0; i < V; i++) dist[i] = INF, used[i] = false;
	dist[s] = 0; Q.push(make_pair(0, s));
	int cnt = 0;
	while (!Q.empty()) {
		if (cnt > E) return; // NEGATIVE_CYCLE
		pair<long long, int> p = Q.top(); used[p.second] = true; Q.pop();
		for (int i = 0; i < X[p.second].size(); i++) {
			int to = X[p.second][i].first; long long leng = X[p.second][i].second;
			if (dist[to] > dist[p.second] + leng && !used[to]) {
				dist[to] = dist[p.second] + leng;
				Q.push(make_pair(dist[to], to));
			}
		}
	}
}
int n, u, v, w; bool r[10]; vector<pair<int, long long> > G[10];
int main() {
	while(cin >> n, n) {
		for(int i = 0; i < 10; i++) G[i].clear(), r[i] = false;
		for(int i = 0; i < n; i++) {
			cin >> u >> v >> w; r[u] = true, r[v] = true;
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
		int x = -1; long long y = INF;
		for(int i = 0; i < 10; i++) {
			long long res = 0;
			if(!r[i]) continue;
			dijkstra(10, n, i, G);
			for(int j = 0; j < 10; j++) {
				if(r[j]) res += dist[j];
			}
			if(y > res) x = i, y = res;
		}
		cout << x << ' ' << y << endl;
	}
}