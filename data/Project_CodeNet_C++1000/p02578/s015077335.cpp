#include <iostream>

int main()
{
	int64_t N;
	std::cin >> N;

	int64_t*  A = (int64_t*)malloc(sizeof(int64_t) * N);
	std::cin >> A[0];
	int64_t Max = A[0];

	int64_t BaseSum = 0;
	for (int i = 1; i < N; i++)
	{
		std::cin >> A[i];
		if (A[i] >= Max)
		{
			Max = A[i];
		}
		else 
		{
			BaseSum += Max - A[i];
		}
	}

	std::cout << BaseSum << std::endl;

	return 0;
}