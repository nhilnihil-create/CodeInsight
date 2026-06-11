#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


int main()
{
	double x1;
	double x2;
	double y1;
	double y2;
	
	cin >> x1 >> y1 >> x2>> y2;
	double d = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
	printf("%lf\n", d);


    return 0;
}