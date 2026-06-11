#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int x = n / 1.08;
	while (x * 1.08 < n) x++;
	if (static_cast<int>(x * 1.08) != n)
		std::cout << ":(" << std::endl;
	else
		std::cout << x << std::endl;
	
	return 0;
}
