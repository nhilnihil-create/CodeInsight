#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

const int MAX = 10000;
vector<int> G[MAX];

vector<int> ans;

bool visited[MAX];

void dfs(int u) {

	visited[u] = true;
	for (int i = 0; i < G[u].size(); ++i) {
		int next = G[u][i];
		if (visited[next] == false) {
			dfs(next);
		}
	}
	ans.push_back(u);
}

int main() {

	int v, e;
	scanf("%d %d", &v, &e);

	for (int i = 0; i < v; ++i) {
		visited[i] = false;
	}

	for (int i = 0; i < e; ++i) {
		int s, t;
		scanf("%d %d", &s, &t);

		G[s].push_back(t);
	}

	for (int i = 0; i < v; ++i) {
		if (visited[i] == false)
			dfs(i);
	}

	for (auto itr = ans.rbegin(); itr != ans.rend(); ++itr) {
		cout << *itr << endl;
	}

	return 0;
}