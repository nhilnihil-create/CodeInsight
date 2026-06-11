#include <iostream>

int main(int argc, char const* argv[])
{
	int a,b;

	std::cin >> a >> b;
	std::cout << a / b << " " << a % b << " " << std::fixed << (double)a / (double)b << std::endl;

	return 0;
}