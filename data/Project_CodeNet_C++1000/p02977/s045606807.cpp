#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, d[maxn];

int main() {
	scanf("%d", &n);
	if((n + 1) % 4 == 0) {
		printf("Yes\n");
		for (int i = 2; i <= 2 * n; ++i) printf("%d %d\n", i - 1, i);
		return 0;
	}
	for (int i = 2; i <= n; ++i) d[i] = d[i >> 1] + 1;
	if(n == (1 << d[n])) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if(n & 1) {
		int U = (1 << d[n]);
		for (int i = 2; i < U; ++i) 
			printf("%d %d\n%d %d\n", i - 1, i, i - 1 + n, i + n);
		printf("%d %d\n", U - 1, n + 1);
		for (int i = U + 1; i <= n; ++i) 
			printf("%d %d\n%d %d\n", i - 1, i, i - 1 + n, i + n);
		printf("%d 1\n1 %d\n", n, U + n);
		return 0;
	}
	if((n + 1) % 4 == 1) {
		int U = (1 << d[n]);
		for (int i = 2; i < U; ++i) 
			printf("%d %d\n%d %d\n", i - 1, i, i - 1 + n, i + n);
		printf("%d %d\n", U - 1, n + 1);
		for (int i = U + 1; i <= n - 1; ++i) 
			printf("%d %d\n%d %d\n", i - 1, i, i - 1 + n, i + n);
		printf("%d %d\n", n - 1, U + n);
		printf("%d %d\n%d %d\n%d %d\n", n, U, U, (n ^ U), (n ^ U), 2 * n);
		return 0;
	}
	printf("%d 1\n1 2\n2 %d\n%d %d\n", n - 1, n, n, 2 * n - 1);
	printf("%d %d\n%d %d\n%d %d\n", 2 * n - 1, 1 + n, 1 + n, 2 + n, 2 + n, 2 * n);
	printf("%d %d\n1 %d\n", n - 2, n - 1, 2 * n - 2);
	printf("3 1\n2 %d\n", 3 + n);
	for (int i = 5; i < n - 2; ++i) 
		printf("%d %d\n%d %d\n", i - 1, i, i - 1 + n, i + n);
	if(n > 6) printf("%d %d\n3 %d\n", n - 3, 4 + n, 4 + n);
	return 0;
}