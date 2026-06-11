#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 11;
const int MAXR = 50;
const int INF = 0x3f3f3f3f;

int d[MAXN][MAXN];
int n, V;

void Floyd() {
	for (int k = 0; k < V; ++k) {
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
void solve() {
	Floyd();
	int resSum = INF, resId = -1;
	for (int i = 0; i < V; ++i) {
		long long cur = 0;
		for (int j = 0; j < V; ++j) {
			cur += d[i][j];
		}
		if (cur < resSum) {
			resSum = cur;
			resId = i;
		}
	}
	printf("%d %d\n", resId, resSum);
}
int main(int argc, char const *argv[])
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < MAXN; ++i) {
			fill(d[i], d[i] + MAXN, INF);
			d[i][i] = 0;
		}
		V = 0;
		for (int i = 0; i < n; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			V = max(V, max(u, v) + 1);
			d[u][v] = w;
			d[v][u] = w;
		}
		solve();
	}
	//system("pause");
	return 0;
}
