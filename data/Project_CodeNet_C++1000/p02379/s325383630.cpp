#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void){
	double x1, x2, y1, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	cout << setprecision(10) << sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) << "\n";

	return 0;
}