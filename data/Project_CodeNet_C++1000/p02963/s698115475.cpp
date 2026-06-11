#include<iostream>
using namespace std;
int main() {
	long long x1, y1, x2, y2, x3, y3, s;
	cin >> s;
	x1 = y1 = 0;
	x2 = 1e9, y2 = 1;
	x3 = (x2 - s % x2) % x2;
	y3 = (s + x3) / x2;
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
	return 0;
}