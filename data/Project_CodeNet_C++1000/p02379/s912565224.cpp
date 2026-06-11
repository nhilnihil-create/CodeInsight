#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

  double a, b, c, d;

  cin >> a >> b >> c >> d;

  double height = c - a;
  double width = d - b;
  double distance = sqrt(pow(height,2) + pow(width, 2));

  cout << fixed << setprecision(6) << distance << endl;
  return 0;

}