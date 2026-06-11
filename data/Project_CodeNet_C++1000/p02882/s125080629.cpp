#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define PI 3.14159265

int main(){
	double a, b, x; cin >> a >> b >> x;
	double s = a * a * b;
	cout << fixed << setprecision(6);
	if (x <= s / 2) cout << 90 - atan(x / (a * b * b) * 2) * 180.0 / PI << '\n';
	else cout << atan((s - x)/(a * a * a / 2)) * 180.0 / PI << '\n';
}
