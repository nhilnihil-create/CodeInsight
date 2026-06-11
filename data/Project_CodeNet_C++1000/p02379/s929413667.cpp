#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	double x1;
	double y1;
	double x2;
	double y2;
	double l;
	double x;
	double y;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	x = x1 - x2;
	y = y1 - y2;
	l = x*x + y*y;
	cout << fixed << sqrt(l) << endl;
	return 0;
}