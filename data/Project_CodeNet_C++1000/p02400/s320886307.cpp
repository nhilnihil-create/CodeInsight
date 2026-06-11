#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double r;
  cin >> r;
  double area = M_PI * r * r;
  double circumference = M_PI * r * 2.0;
  cout << fixed << setprecision(6)
       << area << ' ' << circumference << endl;
  return 0;
}

