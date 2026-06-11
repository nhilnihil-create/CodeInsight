#include <bits/stdc++.h>

int main() {
	int m, d;
	std::cin >> m >> d;
	int ans = 0;
	for (int i = 10; i <= d; i++) {
		int d0 = i % 10, d1 = i / 10;
		if (d0 < 2 || d1 < 2) continue;
		if (0 < d0 * d1 && d0 * d1 <= m) ans++;
	}
	std::cout << ans << "\n";
	return 0;
}