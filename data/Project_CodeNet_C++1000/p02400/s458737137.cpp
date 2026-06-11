#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){
  double r;
  cin >> r;
  cout << fixed << setprecision(10) << pow(r, 2.0) * M_PI << endl;
  cout << fixed << setprecision(10) << 2 * r * M_PI << endl;
  return 0;
}