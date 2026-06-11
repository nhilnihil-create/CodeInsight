#include <iostream>

int main()
{
	int H;
	int W;
	int N;

	std::cin >> H;
	std::cin >> W;
	std::cin >> N;

	int devider = H > W ? H : W;

	int answer;
	if (N % devider == 0)
	{
		answer = N / devider;
	}
	else
	{
		answer = N / devider + 1;
	}

	std::cout << answer;

	return 0;
}
