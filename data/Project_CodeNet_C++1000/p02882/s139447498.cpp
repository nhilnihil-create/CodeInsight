#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  int a, b, x;
  cin >> a >> b >> x;
  int v = a * a * b;
  double ans;
  if (x <= v / 2)
    ans = atan((double)a * b * b / (2.0 * x)) * 180.0 / M_PI;
  else
    ans = atan(2.0 / a * (b - (double)x / (a * a))) * 180.0 / M_PI;
  cout << fixed << setprecision(10) << ans << endl;
  
  return 0;
}