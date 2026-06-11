#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int na, nb, m;
	std::cin >> na >> nb >> m;
	std::vector<int> a(na), b(nb), x(m), y(m), c(m);
	for (auto &e : a) std::cin >> e;
	for (auto &e : b) std::cin >> e;
	for (int i = 0; i < m; i++) {
		std::cin >> x[i] >> y[i] >> c[i];
		x[i]--;
		y[i]--;
	}
	
	int min = *std::min_element(a.begin(), a.end())
		+ *std::min_element(b.begin(), b.end());
	for (int i = 0; i < m; i++) {
		min = std::min(min, a[x[i]] + b[y[i]] - c[i]);
	}
	
	std::cout << min << std::endl;
	
	return 0;
}
