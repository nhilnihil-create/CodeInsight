#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;


int main(void){

	double r;
	cin >> r;
	cout << fixed << setprecision(7) << r*r*M_PI << " " << 2*r*M_PI << endl;
	return 0;
}