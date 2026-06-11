#include <bits/stdc++.h>
using namespace std;

const double pi = 3.141592653589793;

double law_cos(int x, int y, double t){
  double z;
  z  = pow(x * x + y * y - 2 * x * y * cos(t), 0.5);
  return z;
}
 
int main(){
  cout << fixed << setprecision(10);
  int a = 3, b = 4, h = 10, m = 40;
  cin >> a >> b >> h >> m;
  
  double angle_h = (h * pi / 6) + (m * pi / 360);
  double angle_m = m * pi / 30;
  
  //cout << angle_h << " " << angle_m << endl;
  
  double angle;
  if(abs(angle_h - angle_m) <= pi) angle = abs(angle_h - angle_m);
  else angle = 2 * pi - (abs(angle_h - angle_m));
  
  //cout << cos(angle) << endl;
  
  cout << law_cos(a, b, angle) << endl;
}