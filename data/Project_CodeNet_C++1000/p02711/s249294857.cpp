#include<iostream>
using namespace std;

int main()
{
	int a, i, b;

	cin >> a;

	for (i = 0; i < 3; i++) {
		b = a % 10;
		a = a / 10;

		if (b == 7) {
			cout << "Yes";
			break;
		}
		else if (i == 2 && b != 7) {
			cout << "No";
		}
	}




	return 0;
}