#include <bits/stdc++.h>

int n;

void link(int x, int y) { std::cout << x << ' ' << y << '\n'; }

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	if (!(n & n - 1))
		return std::cout << "No\n", 0;
	std::cout << "Yes\n";
	link(1, 3), link(3, 2), link(2, n + 1), link(n + 1, n + 3), link(n + 3, n + 2);
	for (int i = 4; i < n; i += 2)
		link(1, i + 1), link(i + 1, i), link(1, i + n), link(i + n, i + n + 1);
	if (!(n & 1)) {
		int p = 1 << 31 - __builtin_clz(n);
		link(n, p + n), link(n + n, n - p + 1);
	}
	return 0;
}