#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.length(); i += 2)
	{
		if (s.at(i) == 'L')
		{
			std::cout << "No" << std::endl;
			return 0;
		}
	}

	for (int i = 1; i < s.length(); i += 2)
	{
		if (s.at(i) == 'R')
		{
			std::cout << "No" << std::endl;
			return 0;
		}
	}

	std::cout << "Yes" << std::endl;
}