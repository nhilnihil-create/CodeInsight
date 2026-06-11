#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x;
	scanf("%lld", &x);
	long long A, B;
	for(long long i = -300; i <= 300; i++) {
		for(long long j = -300; j <= 300; j++) {
			if((long long)pow(i, 5) - (long long)pow(j, 5) == x) {
				A = i;
				B = j;
				break;
			}
		}
	}
	printf("%lld %lld\n", A, B);
}