#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double A = pow((x2 - x1), 2);
	double B = pow((y2 - y1), 2);
	cout << fixed << setprecision(8) << sqrt(A + B) << endl;
}
