#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
static const int N = 100;

int n;
int M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u) {
	color[u] = GRAY;
	d[u] = ++tt;
	for (int v = 0; v < n; v++) {
		if (M[u][v] == 1 && color[v] == WHITE) {
			dfs_visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = ++tt;
}

void dfs_print() {
	for (int i = 0; i < n; i++) color[i] = WHITE;
	tt = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] == WHITE) {
			dfs_visit(i);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;
	}
}

int main() {
	cin >> n;
	int u, k;
	int index;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			cin >> index;
			M[u - 1][index - 1] = 1;
		}
	}
	dfs_print();
}