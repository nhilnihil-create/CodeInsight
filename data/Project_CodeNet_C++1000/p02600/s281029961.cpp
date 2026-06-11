
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int X;

	cin >> X;

	int result = 0;

	if (400 <= X && X <= 599) {
		result = 8;
	}
	else if (600 <= X && X <= 799) {
		result = 7;
	}
	else if (800 <= X && X <= 999) {
		result = 6;
	}
	else if (1000 <= X && X <= 1199) {
		result = 5;
	}
	else if (1200 <= X && X <= 1399) {
		result = 4;
	}
	else if (1400 <= X && X <= 1599) {
		result = 3;
	}
	else if (1600 <= X && X <= 1799) {
		result = 2;
	}
	else if (1800 <= X && X <= 1999) {
		result = 1;
	}

	cout << result;

	return 0;
}
