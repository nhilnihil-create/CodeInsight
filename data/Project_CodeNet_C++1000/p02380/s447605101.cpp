// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long llong;
using namespace std;

int main() {
	double a, b;
	int c;
	cin >> a >> b >> c;
	double pi = 3.14159265358979323846;
	double S = 0.5*a*b*sin(c*pi / 180);
	double L = a + b + sqrt(a*a + b * b - 2 * a*b*cos(c*pi / 180));
	double h = S * 2 / a;
	cout << fixed << setprecision(10) << S << endl << L << endl << h << endl;
	return 0;
}

