#include <iostream>
#include <vector>

int main()
{
	std::vector<int> hist(100, 0);

	int index = 0;
	int max = 0;
	while (std::cin >> index)
	{
		hist[index - 1]++;
		if (max < hist[index - 1])
		{
			max = hist[index - 1];
		}
	}

	int i = 1;
	for (const auto& h : hist)
	{
		if (h == max)
		{
			std::cout << i << std::endl;
		}
		++i;
	}

	return 0;
}