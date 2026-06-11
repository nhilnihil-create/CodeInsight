#include <bits/stdc++.h>
using namespace std;

int x;
int gcd(const int &a, const int &b);

int main() {
	scanf("%d", &x);
	printf("%d\n", 360 / gcd(360, x));
	return 0;
}

int gcd(const int &a, const int &b) {
	return b == 0 ? a : gcd(b, a % b);
}

