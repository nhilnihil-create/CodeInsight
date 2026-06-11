#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	
	double x1, y1, x2, y2;
	
	while( cin >> x1 >> y1 >> x2 >> y2) {
		
		double dx = x2 - x1, dy = y2 - y1;
		
		cout << fixed << setprecision(8) << sqrt( dx * dx + dy * dy) << "\n";
		
	}
	
	return 0;
}
