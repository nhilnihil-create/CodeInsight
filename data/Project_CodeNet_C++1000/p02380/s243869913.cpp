#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	double a, b, C;
	double S, L, h;

	cin >> a >> b >> C;
	double PI = acos(-1);
	C=C*PI/180;
	S=a*b*sin(C)/2.0;
	L=a + b + sqrt(a*a + b*b -2*a*b*cos(C));
	h=b*sin(C);

	cout <<fixed << S << " " << L <<" " << h << endl;
	return 0;
}
