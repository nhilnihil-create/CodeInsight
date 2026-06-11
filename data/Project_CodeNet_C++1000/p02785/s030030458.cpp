#include <iostream>
#include <algorithm>

int main() {
	long long int n, k;
	std::cin >> n >> k;

	long long int a[200010];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::sort(a, a + n);

	int cnt = std::max(0LL, n - k);
	long long int ans = 0;

	for (int i = 0; i < cnt; ++i)
		ans += a[i];

	std::cout << ans;
}