#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	long long N, K;
	scanf("%lld%lld", &N, &K);
	printf("%lld", min(N % K, K - (N % K)));
	return 0;
}
