#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double rad_h = 2 * M_PI * (h / 12.0 + m / (60.0 * 12.0));
  double rad_m = 2 * M_PI * m / 60.0;
  cout << setprecision(15) << sqrt(pow(a * sin(rad_h) - b * sin(rad_m), 2) + pow(a * cos(rad_h) - b * cos(rad_m), 2)) << endl;
}
