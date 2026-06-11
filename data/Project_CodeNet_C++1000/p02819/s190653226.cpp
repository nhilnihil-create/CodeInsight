#include <iostream>

int main()
{
	int x;
	std::cin >> x;
	
	if (x != 2) {
		if (x % 2 == 0) x++;
		int i;
		while (true) {
			for (i = 3; i * i < x; i += 2) {
				if (x % i == 0) break;
			}
			if (i * i >= x) break;
			x += 2;
		}
	}
	
	std::cout << x << std::endl;
	
	return 0;
}
