#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << setprecision(20) << sqrt(pow(x1-x2, 2.0)+pow(y1-y2, 2.0)) << endl;
  return 0;
}

