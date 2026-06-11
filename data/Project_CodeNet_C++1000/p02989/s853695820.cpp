#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> d(n);
	for (auto &e : d) std::cin >> e;
	
	std::sort(d.begin(), d.end());
	
	std::cout << d[n / 2] - d[n / 2 - 1] << std::endl;
	
	return 0;
}
