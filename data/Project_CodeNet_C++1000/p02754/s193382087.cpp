#include<bits/stdc++.h>
using namespace std ; 


int main() {
  long long  N , A ,B ; 
  cin >> N >> A >> B ; 
  
  long long  i = N % (A+B);
  long long  j = N/(A+B) ; 
  
  
  if(i  <= A ){
    j = j*A  + i ; 
  }
  else {
    j = j*A + A ; 
  }
    
    cout << j << endl ; 
  
  
  
}
