#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int N ; 
  string S  ;

  
  cin >> N ;
  cin >> S ; 
  vector<char> A(N);   
  
  for(int i = 0 ; i < N ; i++){
    A.at(i) = '0' ; 
  }
  
  for(int i = 0 ; i < N-1 ; i++){
    if(S.at(i) != S.at(i+1)){
      A.at(i) = S.at(i) ;
    }
  }     
  int cnt = 0 ; 
  for(int i = 0 ; i < N-1 ; i++){
  	if(A.at(i) == '0') cnt++ ; 
  }
  
  if(S.at(N-1) == '0' ) cnt++ ; 
  
  cout << N-cnt << endl ; 
}
