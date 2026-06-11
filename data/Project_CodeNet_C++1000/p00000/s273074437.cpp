#include <iostream>

int main(int argc, char const* argv[])
{
	for (size_t i = 1; i < 10; i++)
		for (size_t j = 1; j < 10; j++)
			std::cout << i << "x" << j << "=" << i * j << std::endl;


	return 0;
}