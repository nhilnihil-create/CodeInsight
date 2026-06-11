#include <iostream>
#include <vector>

int main()
{
	int n, k, q;
	std::cin >> n >> k >> q;
	std::vector<int> points(n);
	for (int i = 0; i < q; ++i)
	{
		int a;
		std::cin >> a;
		++points[a - 1];
	}

	for (int point : points)
	{
		std::cout << (point > q - k ? "Yes" : "No") << std::endl;
	}
}