#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N, D;
	scanf("%d %d", &N, &D);
	int X[10][10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < D; j++) {
			scanf("%d", &X[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double d = 0;
			for (int k = 0; k < D; k++) {
				d += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
			}
			d = sqrt(d);
			if (floor(d) == d) ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
