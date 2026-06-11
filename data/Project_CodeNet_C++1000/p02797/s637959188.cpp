#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int n, m, sum;
	scanf("%d%d%d", &n, &m, &sum);
	for (int i = 0; i < m; i++) {
		printf("%d ", sum);
	}
	if (sum > 1e5 + 5) {
		for (int i = m; i < n; i++) {
			printf("1 ");
		}
		printf("\n");
	}
	else {
		for (int i = m; i < n; i++) {
			printf("1000000 ");
		}
		printf("\n");
	}
	return 0;
}