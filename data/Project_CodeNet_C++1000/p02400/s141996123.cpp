#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double len(double r);
double width(double r);

int main() {
  double r;
  cin >> r;

  cout << fixed << setprecision(6) << width(r) << " " << len(r) << endl;
  return 0;
}

double len(double r) {
  return 2 * r * M_PI;
}

double width(double r) {
  return r * r * M_PI;
}