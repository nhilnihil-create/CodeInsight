#include <stdio.h>
#include <iostream>

int main(int argc, char const* argv[]) {
	int a,b;
	a = 2, b=100000009;
	std::cin >> a >> b;
	std::cout << a/b << " " ;
	std::cout << a%b << " " ;
	printf("%.8lf\n", static_cast<double>(a)/b);

	return 0;
}