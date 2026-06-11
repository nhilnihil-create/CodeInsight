#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	long a, b, d, r;
	double f;
	cin >> a >> b;
	d = a / b;
	r = a % b;
	f = double(a) / double(b);
	cout << d << " " << r << " " << fixed << setprecision(10) << f << endl;
}