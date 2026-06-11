#include<iostream>
using namespace std;

int main()
{
	int a, b, i;

	cin >> a;

	b = a % 2;

	if (b != 0) {
		cout << a / 2 + b;
	}
	else {
		cout << a / 2;
	}
	return 0;
}