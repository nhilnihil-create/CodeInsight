#include <iostream>
#include <cstdlib>
#include <algorithm>


int main() {
	long long int a, b, c, d;
	long long int m1, m2, m3, m4;

	std::cin >> a >> b >> c >> d;
	m1 = a*c;
	m2 = a*d;
	m3 = b*c;
	m4 = b*d;

	std::cout << std::max({m1, m2, m3, m4}) << "\n";

	return 0;
}