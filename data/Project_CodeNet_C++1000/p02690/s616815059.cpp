#include <iostream>

int main() {
	long long int x;

	std::cin >> x;

	for (long long int i = 0; i <= 1000; ++i)
	{
		for (long long int j = -1000; j <= i-1; ++j) {
			long long int first = i*i*i*i*i;
			long long int second = j*j*j*j*j;

			if (first - second == x) {
				std::cout << i << " " << j;
				return 0;
			}
		}
	}
}