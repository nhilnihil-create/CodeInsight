#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

static const long long FAR = (1LL << 29);
static const int N = 100000;

int n, m;
bool visited[N];
int p[N];

vector<int> G[N];
vector<int> sorted;

void bs(int i) {
	queue<int> q; q.push(i);
	visited[i] = true;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		visited[u] = true;
		sorted.push_back(u);

		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			p[v]--;
			if (p[v] == 0 && !visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

void ts(){
	for (int i = 0; i < n; ++i){
		visited[i] = false;
		p[i] = 0;
	}

	for (int u = 0; u < n; ++u) {
		for (int i = 0; i < G[u].size(); ++i){
			int v = G[u][i];
			p[v]++;
		}
	}
	for (int i = 0; i < n; ++i){
		if (p[i] == 0 && !visited[i]) bs(i);
	}

	for (int i = 0; i < sorted.size(); ++i) cout << sorted[i] << endl;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}

	ts();

	return 0;
}