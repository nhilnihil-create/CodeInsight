#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;

class triangle{
private:
	double a, b, C;
	double S, L, h;
public:
	int set();
	int show();
	int cal();
};

int triangle::set(){
	cin >> a >> b >> C;
	return 0;
}

int triangle::show(){
	cout << fixed << S << endl << L << endl << h << endl;
	return 0;
}

int triangle::cal(){
	S = a * b * sin(C*M_PI / 180) / 2;
	L = a + b + sqrt(a*a + b*b - 2*a*b*cos(C*M_PI / 180));
	h = S * 2 / a;
	return 0;
}

int main()
{
	triangle tri;

	tri.set();
	tri.cal();
	tri.show();

	return 0;
}