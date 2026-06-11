#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  double x1, y1, x2, y2, dist;
  cin >> x1; cin >> y1; cin >> x2; cin >> y2;
  dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  printf("%1.5f\n" , dist);
  return 0;
}