#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int d[100];
	int A[100][100];
	int sunuke[100] = {0};
	for (int i = 0; i < K; i++) {
		scanf("%d", &d[i]);
		for (int j = 0; j < d[i]; j++) {
			scanf("%d", &A[i][j]);
			sunuke[A[i][j] - 1]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (sunuke[i] == 0) ans++;
	}
	printf("%d\n", ans);

	return 0;
}
