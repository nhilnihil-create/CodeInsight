#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

int main(void){
	double r;
	cin >> r;

	cout << fixed << setprecision(20) << r*r*M_PI <<" "<< fixed << setprecision(20) << 2.0*r*M_PI << endl;
	return 0;
}