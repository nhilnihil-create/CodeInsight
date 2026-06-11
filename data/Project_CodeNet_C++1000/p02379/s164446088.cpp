#include<math.h>
#include<iomanip>
#include<iostream>
using namespace std;


int main()
{
	double x1, x2, y1, y2, d;
	cin >> x1 >> y1 >> x2 >> y2;

	d = pow((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1), 0.5);
	cout << fixed << setprecision(6) << d << endl;
	
	return 0;
}
