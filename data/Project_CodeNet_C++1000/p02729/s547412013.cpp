#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d", (N * (N - 1) + M * (M - 1)) / 2);

	return 0;
}
