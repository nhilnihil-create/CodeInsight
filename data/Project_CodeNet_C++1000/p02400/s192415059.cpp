#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159265359

int main() {
	double r;
	cin >> r;

	cout << fixed << setprecision(8) << r * r * PI << " ";
	cout << fixed << setprecision(8) << r * 2 * PI << endl;
}