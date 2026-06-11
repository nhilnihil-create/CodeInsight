/**
 * auther: moririn_cocoa
 */

#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
  
  int A;
  int B;
  
  cin >> A;
  cin >> B;
  
  if ( A <= 9 && B <= 9 ) {
    
    cout << A * B << endl;
  }
  
  else {
    
    cout << -1 << endl;
  }
  
  return 0;
}
