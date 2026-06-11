#include<bits/stdc++.h>
using namespace std ; 

int main () {
  int A , B , C ,K ;
  
  cin >> A >> B >> C >> K ; 
  
  if ( A >= K  ){
    cout << K << endl ; 
    
  }
  
  else if(A+B >= K && A < K){
    cout << A << endl ; 
  }
  
  else if(A+B < K && A+B+C >= K  ){
    cout << A - (K-(A+B)) << endl ; 
  }

  return 0 ; 
  
}
