#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int K, N;
	int A[200100];
	scanf("%d%d", &K, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int gapMax = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			gapMax = max(gapMax, A[0] + (K - A[N - 1]));
		} else {
			gapMax = max(gapMax, A[i] - A[i - 1]);
		}
	}

	printf("%d", K - gapMax);

	return 0;
}
