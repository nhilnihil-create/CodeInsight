#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	int p, q, r;
	std::cin >> p >> q >> r;
	int max = std::max(p, std::max(q, r));
	std::cout << p + q + r - max << '\n';
	return (0);
}