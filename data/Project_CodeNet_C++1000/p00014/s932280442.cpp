#include<iostream>
#include<vector>
int main()
{
	std::vector<int>result;
	for (int d; std::cin >> d;)
	{
		result.push_back(0);
		for (int i = d; i < 600; i += d)
		{
			result.back() += i * i * d;
		}
	}
	for (auto i : result)
	{
		std::cout << i << std::endl;
	}
	return 0;
}
