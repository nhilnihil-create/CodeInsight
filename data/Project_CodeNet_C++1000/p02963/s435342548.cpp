#include<iostream>
using namespace std;

int main(void) {
	long long s;
	cin >> s;

	long long y2 = 1000000000LL, y1 = 1;
	long long x2 = (y2 - s % y2) % y2;
	long long x1 = (s + x2) / y2;
	
	cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	return 0;
}
