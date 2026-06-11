#include<bits/stdc++.h>
using namespace std ; 

int main() {
  string S ; 
  cin >> S ; 
  int cnt = 0 ; 
  int N = S.size() ; 
  
  
    if(N % 2 == 1 ){
    for (int i = 0 ; i < N/2 ;i++){
      if( S.at(i) != S.at(N - i-1)){
        cnt++ ; 
      }
    }
  }
  else {
     for (int i = 0 ; i < N/2 ;i++){
          if( S.at(i) != S.at(N - i-1)){
            cnt++ ; 
          }
        }
  }

  cout << cnt << endl ;
  
  
}