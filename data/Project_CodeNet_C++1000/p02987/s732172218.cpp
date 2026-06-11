#include<bits/stdc++.h>
using namespace std ; 


int main() {
  string S ; 
  cin >> S ; 
  int j = 0 ; 
  int k = 0 ; 
  int l = 0 ; 
  int m = 0 ; 
  
  for(int i = 0 ; i < 4 ; i++){
    if (S.at(0) == S.at(i)){
      j++ ;
    }
    if (S.at(1) == S.at(i)){
      k++ ;
    }
    if (S.at(2) == S.at(i)){
      l++ ;
    }
    if (S.at(3) == S.at(i)){
      m++ ;
    }    
  }
  

  
  if (j != 2 || k != 2 || l != 2 || m != 2 ){
    cout << "No" << endl ; 
  }
  else {
    cout << "Yes" << endl ; 
  }
}