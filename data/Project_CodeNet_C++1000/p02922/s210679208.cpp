#include <iostream>

int main()
{
	int a, b;
	
	std::cin >> a >> b;
	
	a--;
	b--;
	
	std::cout << b / a + !!(b % a) << std::endl;
	
	return 0;
}
