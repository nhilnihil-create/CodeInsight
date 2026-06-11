#include <bits/stdc++.h>

int n;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	scanf("%d", &n), n %= 360;
	printf("%d\n", 360 / gcd(n, 360));
	return 0;
}