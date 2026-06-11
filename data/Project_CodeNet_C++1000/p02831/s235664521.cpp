#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int A , B ; 
  cin >> A >> B ; 
  int64_t N = A*B ; 
  int64_t M = min(A,B) ; 
  int64_t L = max(A,B) ; 
  
  for(int64_t i = 1 ; i <= L ; i++){
    int64_t T = M*i ; 
    
    if( T%L == 0 ){
      cout << T << endl ; 
      return 0 ; 
    }
  }
  
  
}