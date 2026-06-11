#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
	int a, b, h, m;
	cin >> a >> b >> h >> m;

	double aa = (double)a;
	double bb = (double)b;
	double hh = (double)h;
	double mm = (double)m;

	const double PI = 3.14159265358979323846;

	//短針　h/12進む→360*((h+m/60)/12)
	double anglea = (double)(2*PI * (hh+mm/60)/12);
	//長針　m/60進む→360*(m/60)
	double angleb = (double)(2*PI * (mm/60));
	//角度
	double angle = abs(anglea - angleb);

	if (angle > PI)angle=2 * PI - angle;


	//余弦定理
	double length =(double)( aa * aa + bb * bb - 2 * aa * bb * cos(angle));

	cout <<fixed<<setprecision(11)<< (double)sqrt(length) << endl;

	return 0;
}