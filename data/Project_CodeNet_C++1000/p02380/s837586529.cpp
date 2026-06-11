#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c; cin >> a >> b >> c;
	double rad = M_PI/180.0*c;
	double h = b*sin(rad);
	double S = 0.5*a*h;
	double L = a + b + sqrt(a*a+b*b-2*a*b*cos(rad));

	cout << fixed << setprecision(8) << S << endl;
	cout << fixed << setprecision(8) << L << endl;
	cout << fixed << setprecision(8) << h << endl;

	return 0;
}