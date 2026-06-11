#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
	double a, b, c, d, x,y;
	cin >> a >> b >> c >> d;
	x = (c - a) * (c - a) + (d - b) * (d - b);
	y = sqrt(x);
	cout << fixed;
	cout<<setprecision(5)<< y << endl;
}


