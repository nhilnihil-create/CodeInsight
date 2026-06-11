#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int ans = 0;
	while (N > 0) {
		N /= K;
		ans++;
	}

	printf("%d", ans);

	return 0;
}
