#include <stdio.h>
#include <string.h>

int cache[1001][1001];
const int INF = 1 << 20;

int max(int x, int y) { if (x < y) return y; else return x; }

int lcs(char *x, char *y, int xl, int yl) {
	if (cache[xl][yl] != INF) {
		return cache[xl][yl];
	}
	if (xl == 0 || yl == 0) return 0;
	if (x[xl-1] == y[yl-1]) {
		return cache[xl][yl] = lcs(x, y, xl - 1, yl - 1) + 1;
	} else {
		return cache[xl][yl] = max(lcs(x, y, xl - 1, yl), lcs(x, y, xl, yl - 1));
	}
}

int main(void) {
	int q;
	scanf("%d\n", &q);
	for (int i = 0; i < q; i ++) {
		char X[1000];
		char Y[1000];
		for (int i = 0; i <= 1000; i ++) {
			for (int j = 0; j <= 1000; j ++) {
				cache[i][j] = INF;
			}
		}
		gets(X);
		gets(Y);
		printf("%d\n", lcs(X, Y, strlen(X), strlen(Y)));
	}
	return 0;
}