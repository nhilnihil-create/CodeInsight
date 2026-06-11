#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int n, m, s, t;
vector<int> e[100010];
int dp[100010][3];
queue<int> q;
void bfs() {
	dp[s][1] = 1;

	q.emplace(s*3+1);
	while (!q.empty()) {
		int v = q.front() / 3, mod = q.front() % 3;
		q.pop();

		int nc = dp[v][mod] + 1;
		for (int d : e[v])
			if (!dp[d][nc % 3])
				dp[d][nc % 3] = nc, q.emplace(d*3+(nc%3));
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		e[u].emplace_back(v);
	}
	scanf("%d %d", &s, &t);
	bfs();
	if (dp[t][1])
		printf("%d\n", (dp[t][1] - 1) / 3);
	else
		printf("-1\n");
}