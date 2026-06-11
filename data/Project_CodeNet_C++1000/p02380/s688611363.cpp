#include <iostream>
#include <string>
#include <stddef.h>
#include <stack>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#define ll long long;

using namespace std;


int main() {
	int a, b, c;
	double s, l, h;
	cin >> a >> b >> c;
	s = 0.5*a*b*sin(c*3.141592652589/180);
	l = a + b + sqrt(a*a+b*b-2*a*b*cos(c*3.141592652589/180));
	h = 2*s / a;
	printf("%.8f\n%.8f\n%.8f\n", s, l, h);
}