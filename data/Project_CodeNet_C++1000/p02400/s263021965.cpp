#include <iostream>
#include <iomanip>
#define PI 3.14159265359
using namespace std;

int main(void) {
	double r;
	cin >> r;
	cout << fixed << setprecision(6) << r * r * PI << ' ' << (r + r) * PI << endl;
	return 0;
}