#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double a;
	cin >> a;
	cout << fixed <<setprecision(6) <<a*a*M_PI << " " << setprecision(6) <<2*a*M_PI << endl;
	return 0;
}