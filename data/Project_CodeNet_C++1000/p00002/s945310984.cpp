#include <iostream>

int main()
{
	int a;
	int b;
	while (std::cin >> a >> b) {
	int c = a + b;
	if (c < 10)
	{
		std::cout << 1 << std::endl;
	} else if (10 <= c && c < 100)
	{
		std::cout << 2 << std::endl;
	} else if (100 <= c && c < 1000)
	{
		std::cout << 3 << std::endl;
	} else if (1000 <= c && c < 10000)
	{
		std::cout << 4 << std::endl;
	} else if (10000 <= c && c < 100000)
	{
		std::cout << 5 << std::endl;
	} else if (100000 <= c && c < 1000000)
	{
		std::cout << 6 << std::endl;
	} else if (1000000 <= c)
	{
		std::cout << 7 << std::endl;
		} 
	}
	return 0;
}