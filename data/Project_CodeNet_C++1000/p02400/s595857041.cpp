#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14159265359

int main() {
	double r;
	cin >> r;

	double area = PI * r * r;
	double circ = 2 * PI * r;

	cout << fixed << setprecision(6) << area << " " << circ << endl;
	
	return 0;	
}