#include <iostream>
#include <cmath>
using namespace std;

bool func(int x)
{
	bool flag = true;

	for (int i = 3; i <= sqrt(x); i += 2) {
		if (x%i == 0) {
			flag = false;
			break;
		}
	}

	return flag;
}

int main()
{
	while (true) {
		int a, d, n;
		cin >> a >> d >> n;

		if (a == 0 && d == 0 && n == 0) {
			break;
		}

		int count = 0;
		a -= d;

		while (count != n) {
			a += d;

			if (a == 2) {
				count++;
			}
			else if (a % 2 == 1 && a > 1) {
				if (func(a) == true) {
					count++;
				}
			}
		}

		cout << a << endl;
	}

	return 0;
}