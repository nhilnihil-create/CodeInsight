#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  long double x1;
  long double y1;
  long double x2;
  long double y2;
  long double dis;
  
  cin >> x1 >> y1 >>x2 >>y2;
  
  dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  
  cout << fixed << setprecision(5) << dis << "\n";
}