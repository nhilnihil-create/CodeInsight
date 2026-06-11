#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int A[10010];
	for (int i = 0; i < M; i++) {
		scanf("%d", &A[i]);
		N -= A[i];
	}
	if (N < 0) {
		printf("-1");
	} else {
		printf("%d", N);
	}

	return 0;
}
