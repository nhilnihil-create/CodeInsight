#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if(c >= a)
		c -= a, a = 0;
	else
		a -= c, c = 0;
	if(c >= b)
		b = 0;
	else
		b -= c;
	cout << a << ' ' << b;
}
