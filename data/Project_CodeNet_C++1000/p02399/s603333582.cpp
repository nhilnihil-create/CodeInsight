#include <iostream>
#include <iomanip>

int main(int argc, char const* argv[]) {
	int a,b;
	a = 12300;b = 99;
	a = 2, b=100000009;
	std::cin >> a >> b;
	std::cout << a/b << " " ;
	std::cout << a%b << " " ;
	std::cout.precision(50);
	std::cout << std::fixed << std::setprecision(8) <<  static_cast<double>(a)/b << std::endl;
	return 0;
}