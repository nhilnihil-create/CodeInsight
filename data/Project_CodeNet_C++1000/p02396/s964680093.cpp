#include<iostream>

int main()
{
	int i = 0;
	int x;

	while (1) {
		++i;
		std::cin >> x;
		if (0 == x)break;
		std::cout << "Case " << i << ": " << x << std::endl;
	}
}