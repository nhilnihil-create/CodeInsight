#include <iostream>
#include <iomanip>
#include <cmath>	

#define PI 3.14159265359
using namespace std;

int main(){
	double a, b, C, S, L, h;
	cin >> a >> b >> C;
	C = C * PI / 180;
	h = b * sin(C);
	S = a * h / 2;
	L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C));
	cout << fixed << setprecision(9) << S << endl << L << endl << h << endl;
}