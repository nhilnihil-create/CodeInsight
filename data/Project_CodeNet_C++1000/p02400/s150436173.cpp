#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {	

	double PI = atan(1)*4;
	double r;
	cin >> r;
	
	cout << fixed << setprecision(5);	
	cout << PI*r*r << " " << 2*PI*r << endl;	
	
	return 0;
}
