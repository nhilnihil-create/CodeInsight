#include <iostream>
#include <string>

int main()
{
	std::string input;

	std::cin >> input;

	if (input.compare("ABC") == 0)
	{
		std::cout << "ARC";
	}
	else
	{
		std::cout << "ABC";
	}

	return 0;
}
