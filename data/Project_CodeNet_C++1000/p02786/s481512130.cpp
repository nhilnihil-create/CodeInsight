#include <iostream>

int main()
{
	long long h;
	std::cin >> h;
	
	long long i;
	for (i = 1; (h & i) != h; i = i << 1 | 1);
	
	std::cout << i << std::endl;
	
	return 0;
}
