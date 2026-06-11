#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int A[110];
	bool ans = true;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		if (A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0) {
			ans = false;
		}
	}

	printf(ans ? "APPROVED" : "DENIED");

	return 0;
}
