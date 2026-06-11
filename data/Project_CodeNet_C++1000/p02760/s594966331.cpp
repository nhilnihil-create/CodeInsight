#include<bits/stdc++.h>
using namespace std ; 

int main () {
  int N   , A[3][3] ; 
  int C[3][3]   ; 

  
  for( int i = 0 ; i < 3 ; i++){
    for (int j = 0 ; j < 3 ; j++){
      cin >> A[i][j] ; 
      C[i][j] = 0 ; 
    }
    
  }
  
  cin >> N ; 
  int  B[N] ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> B[i] ; 
  }
  
    
  for( int i = 0 ; i < 3 ; i++){
    for (int j = 0 ; j < 3 ; j++){
      for(int k = 0 ; k < N ; k++){
      	if(A[i][j] == B[k]){
        C[i][j] = 1 ; 
        }
      }
    }
  }
  
  for(int i = 0 ; i < 3 ; i++){
    if(C[0][i] * C[1][i] * C[2][i] == 1){
      cout << "Yes" << endl ; 
      return 0 ; 
    }
    
    else if(C[i][0] * C[i][1] * C[i][2] == 1){
      cout << "Yes" << endl ; 
      return 0 ; 
    }
    
    else if(C[0][0] * C[1][1] * C[2][2] == 1){
      cout << "Yes" << endl ; 
      return 0 ; 
    }
    
    else if(C[0][2] * C[1][1] * C[2][0] == 1){
      cout << "Yes" << endl ; 
      return 0 ; 
    }
    
  }
  
  cout << "No" << endl ; 
  

  
  
}

