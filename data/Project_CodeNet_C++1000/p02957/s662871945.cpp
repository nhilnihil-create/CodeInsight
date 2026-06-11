#include<bits/stdc++.h>
using namespace std ; 


int main () {
  int A ,B ; 
  cin >> A >> B ; 
  long K ; 
  K = 0 ; 
  
  while( abs(A-K) != abs(B-K)){
    K++ ; 
    if (K >= 1000000000){
      cout << "IMPOSSIBLE" << endl ; 
      return 0 ; 
    }
  }
  
  cout << K << endl ; 
  
  
  
  
}