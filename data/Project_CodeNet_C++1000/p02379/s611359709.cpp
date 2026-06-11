#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double ret;
	if (x1 - x2 == 0) {
		ret = fabs((y1 - y2));
	} else if (y1 - y2 == 0) {
		ret = fabs((x1 - x2));
	} else {
		ret = sqrt((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
	}

	cout << setprecision(10) << ret << endl;
	return 0;
}

