#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Sqrt(double x1, double y1, double x2, double y2)
{
    double x3, y3;
    double d;
    
    x3 = x1 - x2;
    y3 = y1 - y2;
  
    d = sqrt(x3 * x3 + y3 * y3);
    
    return d;
}

int main()
{
  double x1, y1, x2, y2;
  
  cin >> x1 >> y1 >> x2 >> y2;
  
  cout << setprecision(15) << Sqrt(x1, y1, x2, y2) << endl;
   
   return 0;
}
