#include <bits/stdc++.h>
 using namespace std;

int main(){
  double A,B,H,M;
  double dH,dM,dx,dy,pi;
  cin >> A >> B >> H >> M;
  pi = acos(-1);
  dM = 2 * pi * M / 60;
  dH = 2 * pi * (H+M/60) / 12;
  dx = A*cos(dH)-B*cos(dM);
  dy = A*sin(dH)-B*sin(dM);
  
  cout << fixed << setprecision(20) << sqrt(dx*dx+dy*dy) << endl;

  return 0;
}