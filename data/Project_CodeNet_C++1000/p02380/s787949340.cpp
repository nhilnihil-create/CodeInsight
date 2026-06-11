#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
  double a, b, C;
  cin >> a >> b >> C;
  C = C * M_PI / 180.0;
  cout << fixed << setprecision(10) << a*b*sin(C) / 2.0  << endl;
  double c = sqrt(pow(a, 2.0) + pow(b, 2.0) - 2*b*a*cos(C));
  cout << fixed << setprecision(10) << c + a + b  << endl;
  double sA = c * sin(C) / c;
  cout << fixed << setprecision(10) <<  b * sA << endl;
  return 0;
}