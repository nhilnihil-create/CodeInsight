#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

static const double PI = 3.14159265358979;

int main(){
  double A, B, H, M;
  cin >> A >> B >> H >> M;
  
  H *= 60;
  
  double angle = abs((H + M) / 720 - M / 60);
  //cout << (H + M) / 720;
  if (angle < 0.5) angle = 1 - angle;
  //cout << angle;
  angle = angle * 2 * PI;

  
  double edge1 = sin(angle) * A;
  double edge2 = B - cos(angle) * A;
  
  double edge3 = sqrt(edge1 * edge1 + edge2 * edge2);
  
  cout << setprecision(13) << edge3;
  
  return 0;
}