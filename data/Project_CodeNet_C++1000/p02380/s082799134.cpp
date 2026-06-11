#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#define PI 3.14159265358979323846264

using namespace std;

int main()
{
	double a, b, C;
	cin >> a >> b >> C;
	C = C * PI / 180.0;
	cout << fixed << setprecision(8);
	cout << a * b * sin(C) / 2 << endl;
	cout << a + b + sqrt(a* a + b * b - 2 * a * b * cos(C)) <<endl;
	cout << b * sin(C)<<endl;
	return 0;
}