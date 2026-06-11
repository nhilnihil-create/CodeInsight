#include <iostream>

using namespace std;

int digits(int x)
{
	if (x >= 1000000) return 7;
	if (x >= 100000) return 6;
	if (x >= 10000) return 5;
	if (x >= 1000) return 4;
	if (x >= 100) return 3;
	if (x >= 10) return 2;
	if (x >= 1) return 1;
}
int main()
{
	int a;
	int b;
	int x;
	int y;
	while (cin >> a >> b)
	{
		x = a + b;
		int y = digits(x);
		cout << y << endl;
	}

	return 0;
}
