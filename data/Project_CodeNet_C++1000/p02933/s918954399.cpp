#include <iostream>
#include <string>

int main()
{
	int a = 0;
	std::cin >> a;

	std::string s = "";
	std::cin >> s;

	if (a >= 3200)
	{
		std::cout << s << "\n";
	}
	else
	{
		std::cout << "red\n";
	}

	return 0;
}