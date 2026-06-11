#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
  double r;
  cin >> r;
  double length = 2 * r * M_PI;
  double circle = r * r * M_PI;
  cout << setprecision(20) << circle << " " << length << "\n";
}