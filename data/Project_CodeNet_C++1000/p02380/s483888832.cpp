#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double a,b,C;
	cin >> a >> b >> C;
	cout << fixed << setprecision(5);
	cout << 0.5*a*b*sin(C*M_PI/180) << endl;
	cout << a+b+pow(a*a+b*b-2*a*b*cos(C*M_PI/180),0.5) << endl;
	cout << b*sin(C*M_PI/180) << endl;
	return 0;
}