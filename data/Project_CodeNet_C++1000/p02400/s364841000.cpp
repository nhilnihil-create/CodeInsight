#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double r;
	cin >> r;
	cout << setprecision(20);
	cout << (M_PI*r*r) << " " << (2 * M_PI*r) << endl;
	return 0;
}