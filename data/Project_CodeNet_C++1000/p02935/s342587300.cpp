#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	double v[50];
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::sort(v, v + n);
	for (int i = 1; i < n; i++) {
		v[i] = (v[i - 1] + v[i]) / 2;
	}
	std::cout << v[n - 1] << "\n";
	return 0;
}