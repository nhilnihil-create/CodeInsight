#include <iostream>
#include <cstdint>

int main()
{
	uint64_t H;
	uint64_t W;

	std::cin >> H >> W;

	uint64_t answer;
	if (H == 1 || W == 1)
	{
		answer = 1;
	}
	else if ((H % 2 == 1) && (W % 2 == 1))
	{
		answer = H * W / 2 + 1;
	}
	else
	{
		answer = H * W / 2;
	}
	std::cout << answer;

	return 0;
}
