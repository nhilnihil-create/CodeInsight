#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(){
  double x1,y1,x2,y2;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  double distx = (x2 - x1)*(x2 - x1);
  double disty = (y2 - y1)*(y2 - y1);
  double dist = sqrt(distx + disty);
  printf("%.8lf",dist);
  return 0;
}
