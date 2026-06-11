
#include<iostream>
#include<iomanip>
using namespace std;


int main() {

	double a, b, c, r;
	double pi = 3.141592653589;

	cin >> r; "\n";
	
	a = r * 2;
	b = a * pi;
	c = r * r * pi;

	cout << fixed << setprecision(8) << c << " " << b << "\n";

}