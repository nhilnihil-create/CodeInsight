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
  
  if ( C > A - B ) {
    
    cout << C - A + B << endl;
  }
  
  if ( C <= A - B ) {
    
    cout << 0 << endl;
    
    return 0;
  }
  
}
