#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int buka[200010] = {0};
	for (int i = 0; i < N - 1; i++) {
		int A;
		scanf("%d", &A);
		buka[A - 1]++;
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", buka[i]);
	}
	return 0;
}
