#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <map>
#include <cctype>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

int main()
{
  cout << setprecision(6);
  cout << setiosflags(ios::scientific);
  cout.flags(ios::fixed);

  int a, b, C;
  cin >> a >> b >> C;

  double rad = C * M_PI / 180.0;

  double S = 0.5 * a * b * sin(rad);
  double c = sqrt( b*b + a*a - 2 * b * a * cos(rad));
  double L = a + b + c;
  double h = 2 * S / a;

  cout << S << endl;
  cout << L << endl;
  cout << h << endl;
  
}