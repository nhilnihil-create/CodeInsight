#include<cstdio>
#include<iostream>
using namespace std;

long gcd(long a, long b) {
	if (a < b) swap(a, b);
	while (b > 0) {
		long c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void) {
	long A, B;
	scanf("%ld%ld", &A, &B);

	printf("%ld", A * B / gcd(A, B));

	return 0;
}
