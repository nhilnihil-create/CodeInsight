#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <list>
using namespace std;
static const int MAX = 10000;
static const int INFTY = 1 << 29;

vector<int> g[MAX];
list<int> out;
bool v[MAX];
int n;
int deg[MAX];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	v[s] = true;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		out.push_back(u);

		for (int i = 0; i < g[u].size(); i++) {
			int w = g[u][i];
			deg[w]--;
			if (deg[w] == 0 && !v[w]) {
				v[w] = true;
				q.push(w);
			}
		}
	}
}

void tsort()
{
	for (int i = 0; i < n; i++) {
		deg[i] = 0;
	}

	for (int u = 0; u < n; u++) {
		for (int i = 0; i < g[u].size(); i++) {
			int w = g[u][i];
			deg[w]++;
		}
	}

	for (int u = 0; u < n; u++) {
		if (deg[u] == 0 && !v[u]) bfs(u);
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
		cout << *it << endl;
	}
}

int main()
{
	int s, t, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) v[i] = false;

	for (int i = 0; i < m; i++) {
		cin >> s >> t;
		g[s].push_back(t);
	}

	tsort();

	return 0;
}