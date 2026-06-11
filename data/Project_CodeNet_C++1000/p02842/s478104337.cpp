#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	if (N%27==0) std::cout << N*25/27 << std::endl;
	else {
		int M = N * 25/27 + 1;
		if (M*27/25==N) std::cout << M << std::endl;
		else std::cout << ":(" << std::endl;
	}
	return 0;
}
