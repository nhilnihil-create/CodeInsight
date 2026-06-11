#include<iostream>
using namespace std;

int n, t = 0;
int A[101][101];
int d[101], f[101];

void dfs(int r) {
	d[r] = ++t;
	for (int i = 1; i <= n; i++) {
		if (A[r][i] == 1 && d[i] == 0) dfs(i);
	}
	f[r] = ++t;
	return;
}

int main() {
	int u, v, l;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i] = f[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> u >> l;
		for (int j = 0; j < l; j++) {
			cin >> v;
			A[u][v] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << d[i] << ' ' << f[i] << endl;
	}

	return 0;
}