#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N ;
  string S ; 
  
  cin >> N ;
  cin >> S ; 

  if(S.size() % 2 == 1 ){

    cout << "No" << endl ; 
    return 0 ; 
  }
   else if (S.size() % 2 == 0 ){ 
    for(int i = 0 ; i < N/2 ; i++){

      if( S.at(i) != S.at(N/2 + i  )){
        cout << "No" << endl ; 
        return 0 ; 
      }
    }
  }
 
  cout << "Yes" << endl ; 
  
  
}