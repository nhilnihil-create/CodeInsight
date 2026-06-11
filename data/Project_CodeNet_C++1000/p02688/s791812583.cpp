#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int N , K ;
  cin >> N >> K ; 
  vector<int> T(N)  ; 
  int cnt = 0 ;
  
  for(int i = 0 ; i<N ; i++){
	T.at(i) = 0 ; 
    }
  
  for (int i = 0 ; i<K ; i++){
  	int d=0 ; 
    cin >> d ; 
  	vector<int> A(d) ;
    
    for(int k = 0 ; k < d ; k++){
    cin >> A.at(k) ; 
    T.at(A.at(k)-1) = T.at(A.at(k)-1) + 1 ; 
    }
    
  }
  
      for(int i = 0 ; i<N ; i++){
      if( T.at(i) == 0) {
        cnt++ ; 
      }
    }
      cout << cnt << endl ; 
}