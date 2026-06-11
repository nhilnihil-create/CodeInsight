#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 3 != 0 && i % 5 != 0 ) ans += i;
	}
	printf("%lld", ans);

	return 0;
}
