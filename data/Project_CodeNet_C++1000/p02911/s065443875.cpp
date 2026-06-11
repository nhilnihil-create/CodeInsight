#include <iostream>
#include <vector>

int main() {
	int n, k, q;
	std::cin >> n >> k >> q;
	std::vector<int> a(n, 0);
	for (int i = 0; i < q; i++) {
		int p;
		std::cin >> p;
		a[p - 1]++;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > q - k) {
			std::cout << "Yes" << "\n";
		} else {
			std::cout << "No" << "\n";
		}
	}
	return 0;
}