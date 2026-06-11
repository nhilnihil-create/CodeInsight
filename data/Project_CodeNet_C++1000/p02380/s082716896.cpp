#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define M_PI acos(-1)

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(8) << a*b*sin(M_PI / 180 * c)/2 << endl << a + b + sqrt(a*a+b*b-2*b*a*cos(M_PI/180*c)) << endl << b * sin(M_PI/180*c)<< endl;
}
