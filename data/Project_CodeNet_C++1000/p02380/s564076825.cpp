#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <iomanip>
  
using namespace std;

#define pi 3.141592653589793

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	c = c * pi / 180;
	double s, l, h;
	s = (a * b * sin(c)) / 2;
	l = sqrt((a * a) + (b * b) - 2 * a * b * cos(c)) + a + b;
	h = 2 * s / a;
	printf("%f\n%f\n%f\n", s, l, h);
	return 0;
}