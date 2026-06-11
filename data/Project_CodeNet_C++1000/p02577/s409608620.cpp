#include <iostream>
#include <string>

int ctoi(char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return -1;
	}
}

int main()
{
	std::string n;

	std::cin >> n;

	int sum = 0;
	for (auto c : n)
	{
		sum += ctoi(c);
	}
	if (sum % 9 == 0)
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
	return 0;
}