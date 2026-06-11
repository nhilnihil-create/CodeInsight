#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int a[200010];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int min = -1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			min = a[i];
			++ans;
		}
		else {
			if (a[i] < min) {
				++ans;
				min = a[i];
			}
		}
	}

	std::cout << ans;
}