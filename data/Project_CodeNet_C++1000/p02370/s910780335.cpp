#include<iostream>
#include<vector>
#include<queue>
using namespace std;

static const int MAX = 10000;
static const int WHITE = 0;
static const int BLACK = 1;

int n, e;
int indeg[MAX], color[MAX];
vector<int> L[MAX];
vector<int> vec;

void bfs(int u) {
	queue<int> Q;
	Q.push(u);
	color[u] = BLACK;
	while (!Q.empty()) {
		int uu = Q.front();
		Q.pop();
		vec.push_back(uu);
		for (int i = 0; i < L[uu].size(); i++) {
			int v = L[uu][i];
			indeg[v]--;
			if (indeg[v] == 0) {
				color[v] = BLACK;
				Q.push(v);
			}
		}
	}
}

void TopoligicalSort() {
	for (int i = 0; i < n; i++)	{
		if (color[i] == WHITE && indeg[i] == 0) {
			bfs(i);
		}
	}
}

int main() {
	cin >> n >> e;
	int s, t;

	for (int i = 0; i < n; i++) {
		color[i] = WHITE;
		indeg[i] = 0;
	}

	for (int i = 0; i < e; i++)	{
		cin >> s >> t;
		indeg[t]++;
		L[s].push_back(t);
	}

	TopoligicalSort();

	for (int i = 0; i < n; i++)	{
		cout << vec[i] << endl;
	}

	return 0;

}