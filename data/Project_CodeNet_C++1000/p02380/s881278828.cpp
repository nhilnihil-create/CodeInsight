#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.141592653589793238

int main(){
	int a , b , c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(9) << a*b*sin(PI/180*c)/2 << endl;
	cout << fixed << setprecision(9) << a+b+sqrt(a*a+b*b-2*a*b*cos(PI/180*c)) << endl;
	cout << fixed << setprecision(9) << b*sin(PI/180*c) << endl;
	return 0;
}