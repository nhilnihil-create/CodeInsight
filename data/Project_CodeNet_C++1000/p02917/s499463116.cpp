#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n),b(n - 1);
	for (int i = 0; i < n - 1; i++) {
		std::cin >> b[i];
	}
	a[0] = b[0];
	for (int i = 1; i < n - 1; i++) {
		a[i] = std::min(b[i - 1], b[i]);
	}
	a.back() = b.back();
	std::cout << std::accumulate(a.begin(), a.end(), 0) << "\n";
	return 0;
}