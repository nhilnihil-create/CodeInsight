#include<iostream>
using namespace std;

int main()
{
	int a, b, c, i, d;

	cin >> a >> b >> c;

	for (i = b; i <= c; i++) {
		d = i % a;
		if (d == 0) {
			cout << "OK";
			break;
		}
		else if (i == c && d != 0) {
			cout << "NG";
			break;
		}
	}


	return 0;
}