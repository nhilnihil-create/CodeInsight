#include <iostream>
#include <cmath>
#include <cstdint>

int main()
{
	int64_t a, b, c, d;
	std::cin >> a >> b >> c >> d;

	int64_t num[4] = {a * c, a * d, b * c, b * d};

	int64_t max = num[0];
	for(int i = 1; i < 4; i++)
	{
		if(num[i] > max)
		{
			max = num[i];
		}
	}

	std::cout << max << std::endl;

	return 0;
}