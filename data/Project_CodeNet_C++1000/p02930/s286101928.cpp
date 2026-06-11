#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int g[510][510];

void f(int l, int r, int v) {
	if (r - l <= 1) { return; }
	int m = (r + l) / 2;
	for (int i = l; i < m; ++i) {
		for (int j = m; j < r; ++j) {
			g[i][j] = v;
		}
	}
	f(l, m, v + 1);
	f(m, r, v + 1);
}

int main() {
	int N;
	cin >> N;

	memset(g, 0, sizeof(g));
	f(0, N, 1);
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			cout << g[i][j] << (j < N - 1 ? " " : "\n");
		}
	}

	return 0;
}
