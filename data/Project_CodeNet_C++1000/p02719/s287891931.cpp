#include <iostream>

int main()
{
	long long N, K;
	std::cin >> N >> K;
	long long a = N % K;
	std::cout << std::min(a, K-a) << std::endl;
	return 0;
}
