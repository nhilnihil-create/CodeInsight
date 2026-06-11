#include <iostream>
#include <cmath>
using namespace std;
 
int main(void){
  long double a,b,c;
  cin >> a >> b >> c;
  long double eps = 1.0E-14;
  cout << ((sqrt(a) + sqrt(b) + eps < sqrt(c))?"Yes":"No") << endl;
  return 0;
}
