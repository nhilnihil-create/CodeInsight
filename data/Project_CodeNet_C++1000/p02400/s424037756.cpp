#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double r, a, c;
	cin >> r;
	a=r*r*3.1415926535897932384626433832795028841971693993751058209749;
	c=r*2*3.1415926535897932384626433832795028841971693993751058209749;
	cout << fixed << setprecision(5);
	cout << a << " " << c << endl;
	return 0;
}

