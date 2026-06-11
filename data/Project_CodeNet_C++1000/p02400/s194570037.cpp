#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double r;
	cin >> r;
	cout << fixed << r*r*M_PI << " " << r*2*M_PI << endl;
	
	return 0;
}
