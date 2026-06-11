#include<iostream>
using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	int i = 0;

	if (a == 0 || a == 1) {
		if (b >= 2) {
			i = (b * (b - 1))/2;
		}
		else if (b == 1) {
			i = 0;
		}
	}

	else if (b == 0 || b == 1) {
		if (a >= 2) {
			i = (a * (a - 1))/2;
		}
		else if (a == 1) {
			i = 0;
		}
	}

	else {
		i = (a * (a - 1) + b * (b - 1))/2;
	}

	cout << i;
	return 0;
}