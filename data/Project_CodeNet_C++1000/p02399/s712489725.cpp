#include <iostream>
#include <iomanip>
using namespace std;

int main (int argc, char **argv) {
  long a, b;
  cin >> a >> b;

  long d, r;
  double f;

  d = a / b;
  r = a % b;
  f = (double)a / (double)b;

  cout << d << " " << r << " " << fixed << setprecision(5)<< f << endl;
}