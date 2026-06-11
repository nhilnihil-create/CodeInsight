#include <iostream>
#include <cmath>
#include <iomanip>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

int main(void){
  double a,b,c,d;
  double x,y;
  cin >> a >> b >> c >> d;
  double e;

  x = (a-c)*(a-c);
  y = (b-d)*(b-d);

  e = sqrt(x + y);


 cout << setprecision(10) << e << endl;
}