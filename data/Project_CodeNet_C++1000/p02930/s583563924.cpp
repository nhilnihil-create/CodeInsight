#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			printf("%d%c", __builtin_ctz(i ^ j) + 1, " \n"[j == n]);
	return 0;
}