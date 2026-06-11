#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
  double x1, y1, x2, y2, out;
  cin >> x1 >> y1 >> x2 >> y2;
  out = sqrt(pow(x2-x1, 2.0)+pow(y2-y1, 2.0));
  cout << fixed << setprecision(10) << out << endl;
  return 0;
}