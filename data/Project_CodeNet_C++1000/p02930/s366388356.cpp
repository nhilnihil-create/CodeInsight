#include <bits/stdc++.h>
using namespace std;

int a[510][510];

void dfs(int l, int r, int deep) {
	if (l == r || l == r + 1) return ;
	int mid = l + r >> 1;
	for (int i = l; i <= mid; i++) {
		for (int j = mid + 1; j <= r; j++) {
			a[i][j] = deep;
		}
	}
	dfs(l, mid, deep + 1), dfs(mid + 1, r, deep + 1);
}

int main() {
	int n; scanf("%d", &n);
	dfs(1, n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
