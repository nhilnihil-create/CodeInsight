#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	long long A, B, K;
	scanf("%lld %lld %lld", &A, &B, &K);
	if (A >= K) {
		A -= K;
		K = 0;
	} else {
		K -= A;
		A = 0;
	}

	if (B >= K) {
		B -= K;
		K = 0;
	} else {
		K -= B;
		B = 0;
	}

	printf("%lld %lld", A, B);

	return 0;
}
