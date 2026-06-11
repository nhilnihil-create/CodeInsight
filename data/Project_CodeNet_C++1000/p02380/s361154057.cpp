#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double rad(int x);

int main() {
	int a, b, C;
	cin >> a >> b >> C;
	double S, L, h;
	S = 0.5*a*b*sin(rad(C));
	L = sqrt(a*a + b*b-2*a*b*cos(rad(C)))+a+b;
	h = S * 2 / a;
	cout <<setprecision(20)<< S <<endl;
	cout << L << endl;
	cout << h << endl;

}

double rad(int x) {
	return 1.0*x*M_PI/180;
}