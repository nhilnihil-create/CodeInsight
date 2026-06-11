#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<string.h>
#include<set>

const int MAXN = 1e4;

int degree[MAXN];
int V, E;
std::vector<int> digrath[MAXN];

void init() {
	memset(degree, 0, sizeof(int) * V);
}

void input() {
	scanf("%d%d", &V, &E);
	init();
	for (int i = 0; i < E; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		digrath[s].push_back(t);
		degree[t]++;
	}
}

void output() {
	std::queue<int> q;
	for (int i = 0; i < V; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		printf("%d\n", u);
		for (std::vector<int>::iterator it = digrath[u].begin(); it != digrath[u].end(); it++) {
			degree[*it]--;
			if (degree[*it] == 0) {
				q.push(*it);
			}
		}
	}
}

int main() {
	input();
	output();
	return 0;
}
