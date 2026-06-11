#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
	double a, b, c, C, S, L, h;
	cin >> a >> b >> C;
	c = C/180*acos(-1);
	S = 0.5 * a * b * sin(c);
	L = a + b + sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c));
	h = b * sin(c);
	cout << setprecision(15) << S << setprecision(15) << " " << L << setprecision(15) << " " << setprecision(15) << h << endl;
		return 0;
}