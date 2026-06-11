#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int A, B, C, K;
	scanf("%d %d %d %d", &A, &B, &C, &K);
	int ans = 0;
	ans = min(A, K) - max(K - A - B, 0);
	printf("%d", ans);

	return 0;
}
