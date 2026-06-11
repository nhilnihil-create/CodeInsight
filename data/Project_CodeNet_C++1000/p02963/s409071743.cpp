#include <bits/stdc++.h>

using namespace std;

int main() {
	long long S;
	ignore = scanf("%lld", &S);
	
	int x2 = 1e9;
	int y3 = (S + x2 - 1) / x2;
	int x3 = 1;
	int y2 = x2 * 1ll * y3 - S;
	
	printf("0 0 %d %d %d %d\n", x2, y2, x3, y3);
	
	return 0;
}
