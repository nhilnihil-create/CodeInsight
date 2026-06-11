#include<stdio.h>
#include<algorithm>

int s[10000];

int main() {
	int n;
	int q;
	int cnt = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		for (int i2 = 0; i2 < n; ++i2) {
			if (t == s[i2]) {
				++cnt;
				break;
			}
		}
	}

	printf("%d\n", cnt);
}