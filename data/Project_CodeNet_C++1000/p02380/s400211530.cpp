#include <iostream>
#include <cmath>
#include <iomanip>

double Pi = acos(-1);
using namespace std;
inline double add(double a, double b){
	return abs(a + b) <= 1e-8 ? 0 : a + b;
}
int main(){
	double a, b, C; cin >> a >> b >> C;
	double S = 0.5*a*b*sin(C*Pi/180);
	double h = 2 * S / a;
	double c = sqrt(add(a*a + b*b, - 2 * a*b*cos(C*Pi/180)));
	double L=a+b+c;
	cout << fixed << setprecision(8);
	cout << S << ' ' << L << ' ' << h << '\n';
}