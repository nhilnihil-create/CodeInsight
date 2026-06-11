#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
  double r;
  cin >> r;
  cout << fixed << setprecision(7) << M_PI * pow(r, 2) << " " << 2 * M_PI * r << endl;
  return 0;
}
