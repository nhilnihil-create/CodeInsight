#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;

	int h[100010];
	bool bad[100010] = {0};

	for (int i = 0; i < n; ++i) {
		std::cin >> h[i];
	}

	int x, y;
	while (m--) {
		std::cin >> x >> y;
		--x;
		--y;

		if (h[x] >= h[y])
			bad[y] = true;
		if (h[y] >= h[x])
			bad[x] = true;
	}

	int ans = n;
	for (int i = 0; i < n; ++i)
		if (bad[i])
			--ans;


	std::cout << ans;
}