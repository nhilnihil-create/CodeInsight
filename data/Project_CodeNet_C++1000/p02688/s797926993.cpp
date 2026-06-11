#include <iostream>

int main() {
	int n, k;

	std::cin >> n >> k;

	int cnt[150] = { 0 };
	while (k--) {
		int kcnt;
		std::cin >> kcnt;

		int x;
		for (int i = 0; i < kcnt; ++i) {
			std::cin >> x;
			--x;
			++cnt[x];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (cnt[i] == 0)
			++ans;

	std::cout << ans;
}