#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int gcd2(int a, int b) {
	if (a < b) swap(a, b);
	int c;
	while (1) {
		c = a % b;
		if (c == 0) break;
		a = b;
		b = c;
	}
	return b;
}

int gcd3(int a, int b, int c) {
	return gcd2(a, gcd2(b, c));
}

int main(void) {
	int K;
	scanf("%d", &K);
	long ans = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				ans += gcd3(i, j, k);
			}
		}
	}
	printf("%ld", ans);

	return 0;
}
