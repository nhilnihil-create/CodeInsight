#include <iostream>

int main()
{
	const int monies[] = { 300000 , 200000,100000 };
	const int bounus = 400000;

	int x = 0, y = 0;
	std::cin >> x;
	std::cin >> y;

	int money = 0;
	if (x>=1 && x<=3) {
		money += monies[x - 1];
	}
	if (y >= 1 && y <= 3) {
		money += monies[y - 1];
	}
	if (x + y == 2) {
		money += bounus;
	}
	std::cout << money;
}

