#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

class P {

public:

  double x , y;

  P(int xx, int yy) {

    x = xx;

    y = yy;

  }

};

double getDistance(P p1, P p2) {

  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y , 2));

}

int main() {

  P p1(0 , 0) , p2(0 , 0);

  cin >> p1.x >> p1.y >> p2.x >> p2.y;

  printf("%.8lf\n",getDistance(p1 ,  p2));

  return 0;

}