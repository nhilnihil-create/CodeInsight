#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	b = 2 * b + 1;
	printf("%d\n", (a + b - 1) / b);
}
