#include <iostream>

int main()
{
	int N, M;
	std::cin >> N >> M;

	int64_t sum = 0;
	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		sum += temp;
	}

	if (sum <= N)
	{
		std::cout << N - sum << std::endl;
	}
	else
	{
		std::cout << -1 << std::endl;
	}

	return 0;
}