#include <iostream>
#include <cmath>

int main()
{
	int N, X, T;

	std::cin >> N >> X >> T;

	std::cout << (int)ceil((double)N / (double)X) * T << std::endl;
	return 0;
}