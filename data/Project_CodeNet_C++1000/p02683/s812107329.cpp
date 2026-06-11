#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);
	int C[12];
	int A[12][12];
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	int ans = 1<<30;
	bool ansFound = false;
	// cout << ans << "\n";
	for (int bit = 0; bit < (1 << N); bit++) {
		int sum = 0;
		int skill[12] = {0};
		for (int i = 0; i < N; i++) {
			if (bit & (1 << i)) {
				sum += C[i];
				for (int j = 0; j < M; j++) {
					skill[j] += A[i][j];
				}
			}
		}
		bool flag = true;
		for (int j = 0; j < M; j++) {
			// cout << sum << " " << skill[j] << "\n";
			if (skill[j] < X) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = min(ans, sum);
			ansFound = true;
		}
	}
	if (ansFound) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}
