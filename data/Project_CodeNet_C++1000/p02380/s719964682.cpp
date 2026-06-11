#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	
	double a, b, c;
	
	while( cin >> a >> b >> c  ) {
		
	double area = a * b * sin(c * M_PI / 180) / 2;
	double d = sqrt(a * a + b * b - 2 * a * b * cos(c * M_PI / 180 ));
	double premeter = a + b + d;
	double h = area * 2 / a;
		
	cout << fixed << setprecision(6)
		 << area << "\n"
		 << premeter << "\n"
		 << h << "\n";
		
	}
	
	return 0;
}
