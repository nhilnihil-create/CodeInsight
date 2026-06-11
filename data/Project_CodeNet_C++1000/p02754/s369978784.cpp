#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	long long N, A, B;
	scanf("%lld %lld %lld", &N, &A, &B);
	long long set = N / (A + B);
	long long r = N % (A + B);
	printf("%lld", A * set + min(A, r));

	return 0;
}
