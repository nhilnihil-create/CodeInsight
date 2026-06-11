#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	while (true) {
		c -= b;
		if (c <= 0) return 0 * printf("Yes\n");
		a -= d;
		if (a <= 0) return 0 * printf("No\n");
	}
}
