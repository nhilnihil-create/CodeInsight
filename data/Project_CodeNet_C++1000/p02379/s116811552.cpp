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

  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  double res = pow(x1-x2, 2) + pow(y1-y2,2);
  cout << sqrt(res) << endl;

}