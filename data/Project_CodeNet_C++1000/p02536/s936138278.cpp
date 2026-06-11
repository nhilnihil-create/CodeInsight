#include <iostream>
#include <vector>
using namespace std;
#define MAX 100005
int n, m;
bool visited[MAX];
vector<int> graph[MAX];

void DFS(int u) {
	visited[u] = true;
	for (int i = 0;i < graph[u].size();i++) {
		int v = graph[u][i];
		if (!visited[v])
			DFS(v);
	}
}

int main()
{
	int testcase, u, v, num;

		cin >> n;
		cin >> m;
		for (int i = 0;i < m;i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int u = 0;u <= n;u++)
			visited[u] = false;

		num = 0;
		for (int u = 1;u <= n;u++) {
			if (!visited[u]) {
				num++;
				DFS(u);
			}
		}
  cout << num - 1;
}
