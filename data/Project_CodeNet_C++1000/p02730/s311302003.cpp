#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ;
  int N ;
  N = S.size() ; 
  
  for(int i = 0 ; i< N/2 ; i++){
    if(S.at(i) == S.at(N-1-i) && S.at(i) == S.at(N/2-i-1)){
      continue ; 
    }
    else{
      cout << "No" << endl ; 
      return  0 ; 
    }
  }
  
  cout << "Yes" << endl ; 
}