#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	long long N, A, B;
	scanf("%lld %lld %lld", &N, &A, &B);
	long long set = N / (A + B);
	if (N - (A + B) * set >= A) {
		printf("%lld", A * set + A);
	} else {
		printf("%lld", A * set + (N - ( A + B ) * set));
	}

	return 0;
}
