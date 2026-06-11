#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N ;
  cin >> N ; 
  double  C = 0 ; 
  vector<double> A(N)  , B(N) ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> A[i] ; 
    B[i] = 1/A[i]  ;
    C = C + B[i] ; 
  }
  
  
  cout << 1/C << endl ; 
  
}
