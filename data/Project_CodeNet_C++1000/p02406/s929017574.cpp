#include <iostream>

int main(int argc, char const* argv[])
{
	int n;
	std::cin >> n;

	int i = 1;

	while(++i <= n)
	{
		int x = i;
		if ( x % 3 == 0 )
			std::cout << " " << i;
		else
		{
			do {
				if ( x % 10 == 3 )
				{
					std::cout << " " << i;
					x = 0;
				}
				x /= 10;
			} while(x);
		}
	}
	std::cout << std::endl;
	return 0;
}