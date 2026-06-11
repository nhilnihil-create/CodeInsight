#include <bits/stdc++.h>

int main() {
	long long S, S1;
	scanf("%lld", &S);
	int x3 = 0, y3 = 0;
	S1 = S;
	if(S % 1000000000 != 0) {
		S1 = (S / 1000000000 + 1) * 1000000000;
	}
	int x1 = 1000000000, y2 = S1 / x1;
	int x2 = S1 - S, y1 = 1;
	printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
}