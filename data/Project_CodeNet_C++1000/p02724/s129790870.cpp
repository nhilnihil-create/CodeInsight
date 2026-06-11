#include<bits/stdc++.h>
using namespace std ; 


int main() {
  int X , Y , Z ; 
  cin >> X ; 
  Z = 0 ;
  Y = 0 ; 
  
  while( X >= 500){
    X = X - 500 ; 
    Z++ ;
  }
  
  while(X >= 5 ){
    X = X - 5 ; 
    Y++ ; 
  }
  
  cout << 1000*Z + 5*Y << endl ; 
  
  
  
}

