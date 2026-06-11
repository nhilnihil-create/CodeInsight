#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int mxN = 2e3 + 5;
vector<int> adj[mxN];
int dis[mxN][mxN], cnt[mxN];

int main() {
	int n, u, v;
	cin >> n >> u >> v;
	adj[u].push_back(v);
	adj[v].push_back(u);
	for(int i = 1; i < n; ++i)
		adj[i].push_back(i + 1),
		adj[i + 1].push_back(i);
	memset(dis, -1, sizeof dis);
	for(int i = 1; i <= n; ++i) {
		queue<pair<int ,int>> bfs;
		bfs.push({i, 0});
		while(!bfs.empty()) {
			pair<int, int> cur = bfs.front();
			bfs.pop();
			if(~dis[i][cur.first])
				continue;
			dis[i][cur.first] = cur.second;
			for(int x : adj[cur.first])
				if(dis[i][x] == -1)
					bfs.push({x, cur.second + 1});
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			++cnt[dis[i][j]];
	for(int i = 1; i < n; ++i) 
		cout << cnt[i] << '\n';
}
