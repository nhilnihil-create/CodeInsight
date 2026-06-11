#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	if (K == 1) printf("0\n");
	else printf("%d\n", (N - (K - 1)) - 1);
	return 0;
}
