#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  double x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(6) << sqrt(pow((x1-x2), 2)+pow((y1-y2), 2)) << endl;
  return 0;
}