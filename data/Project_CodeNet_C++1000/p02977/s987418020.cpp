#include <bits/stdc++.h>
using namespace std;

void p (int x, int y) {
	printf("%d %d\n", x, y);
	
}

int main (void) {
	int n;
	scanf("%d", &n);
	if (n == 3) {
		puts("Yes");
		p(1, 2);
		p(2, 3);
		p(3, 4);
		p(4, 5);
		p(5, 6);
	} else if (n <= 2) {
		puts("No");
	} else if (n & 1) {
		puts("Yes");
		p(1, 2);
		p(2, 3);
		p(3, n + 1);
		p(n + 1, n + 2);
		p(n + 2, n + 3);
		for (int i = 4; i <= n; i += 2) {
			p(i, i + 1);
			p(i + 1, 1);
			p(1, i + n);
			p(i + n, i + n + 1);
		}
	} else {
		int m = (n) & (-n);
		if (m == n) {
			puts("No");
			return 0;
		} 
		puts("Yes");
		p(n + n, m + n);
		p(n, (n - m) ^ 1);
		p(1, 2);
		p(2, 3);
		p(3, n + 1);
		p(n + 1, n + 2);
		p(n + 2, n + 3);
		for (int i = 4; i < n; i += 2) {
			p(i, i + 1);
			p(i + 1, 1);
			p(1, i + n);
			p(i + n, i + n + 1);
		}
	}
}