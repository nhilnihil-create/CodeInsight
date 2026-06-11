#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const double pi = 3.141592653589;
	double r;
	cin >> r;
	cout << fixed << setprecision(7) << r * r * pi << " " << 2 * pi * r << endl;
}