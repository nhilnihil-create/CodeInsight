#include<bits/stdc++.h>
using namespace std ; 

int64_t f(int64_t H1){
  
  if (H1 > 1){
    int64_t  s = f( int64_t (H1)/2) ; 
    return  2*s + 1; 
  }
  else if (H1 == 1){
    return 1 ; 
  }
  
}



int main (){
  int64_t H1  ;
  cin >> H1  ;
  
  cout << f(H1) << endl ; 
  
}