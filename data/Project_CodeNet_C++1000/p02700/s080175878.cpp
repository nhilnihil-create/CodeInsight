#include<bits/stdc++.h>
using namespace std ; 

int main () {
  int A , B, C, D ; 
  int T1 , T2 ; 
  cin >> A >> B >> C >> D ; 
  
  T1 = 0 ;
  T2 = 0 ; 
  
  while (A > 0 ){
    A = A - D ; 
    T2++ ; 
  }
  
    
  while (C > 0 ){
    C = C - B ; 
    T1++ ; //takahashi turn 
  }
  
  if( T2 >= T1){
    cout << "Yes" << endl ;  
  }
  else{
    cout << "No" << endl ;  
  }
  
  return 0 ; 
  
}