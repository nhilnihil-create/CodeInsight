#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
    
int main()
{
	double p1x, p1y, p2x, p2y, l;
	cin >> p1x >> p1y >> p2x >> p2y;
	l = pow((p2x-p1x),2)+pow((p2y-p1y),2);
	l = sqrt(l);
	cout << fixed << setprecision(4) <<l << endl;
	return 0;
}