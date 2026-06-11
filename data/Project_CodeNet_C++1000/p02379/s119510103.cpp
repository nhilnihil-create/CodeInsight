#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

	long double x1;
	long double x2;
	long double y1;
	long double y2;
	long double X, Y;

	cin >> x1 >> y1 >> x2 >> y2;

	X = -(x1 - x2);
	Y = -(y1 - y2);

	long double A = pow(X, 2);
	long double B = pow(Y, 2);

	

	long double C = A + B;

	cout <<fixed<< sqrt(C) << endl;












	return 0;
}