#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <cstdlib>
#include <string.h>
#include <math.h>


using namespace std;


int main()
{
	long double x1, x2, y1, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	 long double distance = pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0);
	 

	distance = sqrt(distance);

	cout << fixed << distance << endl;

	
}