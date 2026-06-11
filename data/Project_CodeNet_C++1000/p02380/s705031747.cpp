#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double Sines(double a, double b, double Z){
	double S = a * b * sin(Z) / 2;
	return S;
}

double Cosines(double a, double b, double Z){
	double c = sqrt( a * a + b * b - 2 * a * b * cos(Z) );
	return c;
}

int main(){
	double a, b;
	int C;
	cin >> a >> b >> C;
	double Z = M_PI * C / 180;
	double S = Sines(a, b, Z);
	double c = Cosines(a, b, Z);
	double L = a + b + c;
	double h = 2 * S / a;
	cout << fixed << setprecision(8) << S << endl << L << endl << h << endl;
	return 0;
}