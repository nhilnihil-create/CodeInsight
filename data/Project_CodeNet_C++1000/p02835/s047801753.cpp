/**
 * auther: moririn_cocoa
 */

#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
  
  int A;
  int B;
  int C;
  
  cin >> A;
  cin >> B;
  cin >> C;
  
  if ( A + B + C <= 21 ) {
    
    cout << "win" << endl;
  }
  
  else if ( A + B + C >= 22 ) {
    
    cout << "bust" << endl;
  }
  
  return 0;
}