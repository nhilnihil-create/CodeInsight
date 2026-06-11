#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N ; 
  cin >> N ;
  vector<int> W(N) , M(N)  ; 
  int R = 0 ; 
  int L = 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> W.at(i) ; 
  }
  
  for(int i = 0 ; i < N ; i++){//仕切り
    
      for(int j = 0 ; j < N ; j++){ 
        if( i <  j ){ //仕切りが左
			L = L + W.at(j) ; 
        }
        else{
            R = R + W.at(j) ; 
        }

      }
    
    //cout << L << " "<< R << endl ;
    M.at(i) = abs(L - R) ; 
    L = 0 ; 
    R = 0 ; 
  }
  
  sort(M.begin(),M.end()) ; 
  cout << M.at(0) << endl ; 
  
}