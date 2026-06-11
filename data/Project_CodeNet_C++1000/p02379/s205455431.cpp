#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	cout  << fixed << setprecision(8) << sqrt((a - c) * (a - c) + (b - d) * (b - d)) << endl;
	cin >> a;
}
