#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(int argc, char* argv[]) {
  double r;
  cin >> r;
  cout << fixed << setprecision(6) << r*r*M_PI << " " << 2*r*M_PI << endl;

  return 0;
}