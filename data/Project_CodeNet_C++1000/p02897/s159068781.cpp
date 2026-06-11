#include<bits/stdc++.h>
using namespace std ; 


int main() {
  int N ; 
  cin >> N ; 
  double O ; 
  
  if ( N % 2 == 0 ){
    O = 1.0/2.0 ; 
    cout << O << endl ; 
  }
  else {
    O = (N+1.0)/(2.0*N) ; 
    cout << O << endl ; 
  }
  
}