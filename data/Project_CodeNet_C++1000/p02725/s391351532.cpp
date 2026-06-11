#include <iostream>
#include <vector>
#include <utility>

int main()
{
	int k, n;
	std::cin >> k >> n;
	std::vector<int> a(n);
	for (auto &e : a) std::cin >> e;
	
	std::vector<int> b(n);
	b[0] = a.front() + k - a.back();
	for (int i = 1; i < n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	
	std::cout << k - *std::max_element(b.begin(), b.end()) << std::endl;
	
	return 0;
}
