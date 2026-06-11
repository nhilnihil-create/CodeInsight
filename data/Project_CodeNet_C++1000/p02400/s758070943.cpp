#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main(void){
	double r;

	cin >> r;

	cout << fixed << setprecision(6) << r*r*M_PI << " " << 2 * r*M_PI << "\n";

	return 0;
}