#include <iostream>
#include <iomanip>

#define PI 3.141592653589

using namespace std;

int main() {
	double r, s, l;
	cin >> r;

	l = 2*PI*r;
	s = r*r*PI;

	cout << fixed << setprecision(5) << s << " " << l << endl;

	return 0;
}