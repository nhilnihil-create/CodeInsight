#include <iostream>
#include <vector>
#include <algorithm>

bool isPrimenumber(const int n);

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);

	int numPrimeNumber = 0;
	int inputNumber = 0;

	for (int i = 0; i < n; i++)
	{
		std::cin >> inputNumber;
		if (isPrimenumber(inputNumber))
		{
			numPrimeNumber++;
		}
	}
	std::cout << numPrimeNumber << std::endl;
	return 0;
}

bool isPrimenumber(const int n)
{
	int loopLimit = (int)std::sqrt(n);
	for (int i = 2; i <= loopLimit; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}