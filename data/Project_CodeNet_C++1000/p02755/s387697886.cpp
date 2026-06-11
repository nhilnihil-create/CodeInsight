#include<bits/stdc++.h>
using namespace std ;

int main() {
  int A , B ; 
  cin >> A >> B ; 
  
  
  for( int i = 1 ; i <= 1010 ; i++){
    if(floor(0.08*i) == A && floor(0.1*i) == B){
      cout << i << endl ; 
      return 0 ; 
    }
  }
  
  cout << "-1" << endl ; 
  
  
}

