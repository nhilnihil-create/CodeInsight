#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <cstdio>





using namespace std;


int main()
{
	double S, L, h, a, b ,C;
	double pi = 3.14159265359;

	cin >> a >> b >> C;

	h = b * sin(C * pi / 180.00);
	L = sqrt(pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(C * pi / 180)) + a + b;
	S = a * h / 2;

	cout << fixed << S << endl <<  L << endl << h << endl;
	

	
}