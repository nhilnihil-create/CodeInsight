// practice with Dukkha
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 1000, N_ = N * N;

int oo[N_], *oj[N_];

void init(int n) {
	for (int i = 0; i < n; i++)
		oj[i] = (int *) malloc(2 * sizeof *oj[i]);
}

void link(int i, int j) {
	int o = oo[i];
	if (o >= 2 && (o & o - 1) == 0)
		oj[i] = (int *) realloc(oj[i], (o << 1) * sizeof *oj[i]);
	oj[i][oo[i]++] = j;
}

int qu[N_], cnt;
char used[N_];
int dp[N_];

bool dfs(int i) {
	if (used[i])
		return used[i] == 1;
	used[i] = 1;
	for (int o = 0; o < oo[i]; o++) {
		int j = oj[i][o];
		if (dfs(j))
			return true;
	}
	used[i] = 2;
	qu[--cnt] = i;
	return false;
}

int main() {
	int n; cin >> n;
	int n_ = n * n;
	init(n_);
	for (int i = 0; i < n; i++)
		for (int u = -1, h = 0; h < n - 1; h++) {
			int j; cin >> j, j--;
			int v = i < j ? i * n + j : j * n + i;
			if (h)
				link(u, v);
			u = v;
		}
	cnt = n_;
	for (int u = 0; u < n_; u++)
		if (dfs(u)) {
			cout << "-1\n";
			return 0;
		}
	int ans = 0;
	for (int h = 0; h < n_; h++) {
		int i = qu[h];
		int x = dp[i] + 1;
		ans = max(ans, x);
		for (int o = 0; o < oo[i]; o++) {
			int j = oj[i][o];
			dp[j] = max(dp[j], x);
		}
	}
	cout << ans << '\n';
	return 0;
}
