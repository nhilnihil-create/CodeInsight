//Triangle
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	long long S, x1 = 1000000000, x2 = 1, y1, y2, z1 = 0, z2 = 0, q, r;
	cin >> S;
	if (S == pow(10, 18)) {
		y2 = pow(10, 9);
		y1 = 0;
	}
	else {
		r = S % x1;
		q = S / x1;
		y2 = q + 1;
		y1 = x1 - r;
	}
	cout << x1 << " " << x2 << " " <<  y1 << " " << y2 << " " << z1 << " " << z2 << endl;
	return 0;
}