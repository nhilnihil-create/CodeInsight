#include <iostream>
#include <cmath>

int main()
{
	long double N, D, Y, X;
	int count = 0;
	std::cin >> N >> D;

	for (; N--;)
	{
		std::cin >> Y >> X;

		if(sqrt(pow(Y, 2) + pow(X, 2)) <= D)
			count++;
	}
	std::cout << count;

}