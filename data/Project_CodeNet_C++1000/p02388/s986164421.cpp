#include <iostream>
#include <cctype>
#include <cstdlib>
#include <locale>

static bool input(int &n)
{
	std::string s;
	std::locale loc;

	if (0x00 == &n) {
		return false;
	}

	std::cin >> s;
	if (std::isdigit(s[0], loc)) {
		n = std::atoi(s.c_str());
		return true;
	}

	return false;
}

static int xCubic(const int x)
{
	return x * x * x;
}

int main()
{
	int n;

	if (true == input(n)) {
		std::cout << xCubic(n) << '\n';
	}

	return (0);
}