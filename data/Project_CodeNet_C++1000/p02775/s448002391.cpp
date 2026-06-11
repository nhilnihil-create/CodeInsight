#include <iostream>
#include <vector>
#include <algorithm>


constexpr size_t MAX_SIZE = 1000000;

int main()
{
	std::string N;
	int sum = 0, kuri = 0, kuri5 = 0;

	std::cin >> N;

	for (auto it = N.rbegin(); it != N.rend(); ++it)
	{
		int ci = *it - '0' + kuri;
		if (ci >= 5) ci += kuri5;

		kuri5 = 0;
		kuri = 0;

		if (ci < 5)
		{
			sum += ci;
		}
		else if (ci > 5)
		{
			sum += 10 - ci;
			kuri = 1;
		}
		else
		{
			sum += 5;
			kuri5 = 1;
		}
	}

	sum += kuri;

	std::cout << sum;
}