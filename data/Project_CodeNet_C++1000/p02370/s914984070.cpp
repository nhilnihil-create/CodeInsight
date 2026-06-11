#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

const int MAX = 10000;
vector<int> V[MAX];
int NIL = -1;

int color[MAX];
int WHITE = 0;
int GRAY = 1;

vector<int> ans;

void dfs(int u) {

	color[u] = GRAY;
	for (int i = 0; i < (int) V[u].size(); ++i) {
		int next = V[u][i];
		if (color[next] == WHITE)
			dfs(next);
	}
	ans.push_back(u);
}

int main() {

	int v, e;
	scanf("%d %d", &v, &e);

	for (int i = 0; i < v; ++i) {
		color[i] = WHITE;
	}

	for (int i = 0; i < e; ++i) {
		int s, t;
		scanf("%d %d", &s, &t);
		V[s].push_back(t);
	}

	for (int i = 0; i < v; ++i) {
		if (color[i] == WHITE)
			dfs(i);
	}

	for (auto itr = ans.rbegin(); itr != ans.rend(); ++itr) {
		cout << *itr << endl;
	}

	return 0;
}