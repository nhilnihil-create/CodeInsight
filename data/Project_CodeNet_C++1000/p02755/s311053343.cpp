#include <iostream>
#include <cmath>

using namespace std;
int main(){
  double a, b;
  cin >> a >> b;
  double xa, xb;
  bool exist = false;
  for(xb = 10*b; floor(xb*0.1) == b; xb++) {
    if(floor(xb*0.08) == a) {
      exist = true;
      break;
    }
  }
  if(exist) {
   cout << xb << endl;
  } else {
   cout << -1 << endl;
  }
   return 0;
} 
