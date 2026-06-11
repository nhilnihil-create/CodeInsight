#include <iostream>
#include <cstdio>

int main()
{
	int a, b;
	std::cin >> a >> b;
	printf("%d %d %.5f", a/b, a%b, static_cast<double>(a)/static_cast<double>(b));
	return 0;
}