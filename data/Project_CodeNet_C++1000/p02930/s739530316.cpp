#include <bits/stdc++.h>

const int maxn = 501;
std::map<int, int> m;

int main() {
	for(int i = 0; i < 10 && (1 << i) < maxn; ++i)
		m[1 << i] = i;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	for(int j = i + 1; j < n; ++j)
		printf("%d%c", m[(i ^ j) & -(i ^ j)] + 1, " \n"[j == n - 1]);
	return 0;
}
