#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int N ; 
  cin >> N ; 
  vector<int> A(N+1) , B(N+1) ; 
  
  for(int i = 1 ; i <= N ; i++){
    B.at(i) = 0 ; 
  }
  
  for(int i = 1 ; i <= N-1 ; i++ ){
    cin >> A.at(i) ;
    B.at(A.at(i))++ ; 
  }
  
  for(int i = 1; i <= N ; i++){
    cout  << B.at(i) << endl ; 
  }
  
}