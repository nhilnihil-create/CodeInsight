#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//---------------------------------------
//---------------------------------------

int main(void)
{
	double x1, y1, x2, y2;
	cout << fixed <<setprecision(4);
	
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	
	cout << sqrt(pow((x1 - x2), 2) + pow((y1- y2), 2)) << endl;
	
	return 0;
	
	
}