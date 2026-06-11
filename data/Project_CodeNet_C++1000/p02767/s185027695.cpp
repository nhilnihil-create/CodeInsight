#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N;
	int X[100];
	scanf("%d", &N);
	int minx = 100, maxx = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
		minx = min(minx, X[i]);
		maxx = max(maxx, X[i]);
	}
	int ans = 20000000;
	for (int i = minx; i <= maxx; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += (X[j] - i) * (X[j] - i);
		}
		ans = min(ans, sum);
	}
	printf("%d", ans);

	return 0;
}
