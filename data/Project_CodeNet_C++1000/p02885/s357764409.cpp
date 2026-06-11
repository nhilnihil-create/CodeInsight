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

  if ( B * 2 < A ) {
    
    cout << A - ( B * 2 ) << endl;
  }
  
  else if ( B * 2 >= A ) {
    
    cout << 0 << endl;
  }
  
  return 0;
}
