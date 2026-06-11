#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int H , N ; 
  cin >> H >> N ; 
  int A[N] ; 
  int B= 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> A[i] ;  
    B = B + A[i] ; 
  }
  
  if(B >= H){
    cout << "Yes" << endl ; 
    
  }
  else{
    cout << "No" << endl ;
  }
  
  
}