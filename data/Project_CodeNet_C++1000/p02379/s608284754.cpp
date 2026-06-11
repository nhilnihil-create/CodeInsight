#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
 
int main()
{
  double x1,y1;
  double x2,y2;
  double dist;

  cin >> x1 >> y1 >> x2 >> y2;

  dist = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));

  cout << fixed
       << setprecision(5)
       << dist
       << endl;

  return(0);
}