#include <iostream>
#include <utility>

int main()
{
	long long n, a, b;
	std::cin >> n >> a >> b;
	
	long long c = n / (a + b) * a;
	n %= (a + b);
	c += std::min(n, a);
	
	std::cout << c << std::endl;
	
	return 0;
}
