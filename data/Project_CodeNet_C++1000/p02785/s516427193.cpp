#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);
	int H[200010];
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
	sort(H, H + N, greater<int>());
	long long ans = 0;
	for (int i = K; i < N; i++) {
		ans += H[i];
	}
	printf("%lld", ans);

	return 0;
}
