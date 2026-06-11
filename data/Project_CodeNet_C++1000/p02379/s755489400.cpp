#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(int argc, char* argv[])
{
  double x1,y1,x2,y2;
  double distance;
  cin >> x1 >> y1 >> x2 >> y2;
  distance = sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
  printf("%.8lf\n",distance);
  return 0;
}