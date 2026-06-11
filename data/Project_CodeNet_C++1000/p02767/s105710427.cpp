#include <bits/stdc++.h>

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int &i : a) std::cin >> i;

    int ans = INT_MAX;
	
	for (int p = 1; p <= 100; p++) {
		int stamina = 0;
		for (int i : a) stamina += (i - p) * (i - p);

		ans = std::min(ans, stamina);
	}

	std::cout << ans;

    return 0;
}