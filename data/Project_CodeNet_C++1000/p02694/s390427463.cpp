#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	long long X;
	scanf("%lld", &X);
	long long ans = 0;
	long long deposit = 100;
	while (deposit < X) {
		deposit += deposit / 100;
		ans++;
	}

	printf("%lld", ans);

	return 0;
}
