#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	int* array01 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		array01[i] = 0;
	}

	for (int i = 1; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		array01[temp-1]++;
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << array01[i] << std::endl;
	}

	return 0;
}