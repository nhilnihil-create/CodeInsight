#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N , D ; 
  cin >> N >> D ; 
  int cnt = 0 ; 
  
  vector<vector<int>> X(N , vector<int>(D)) ; 
  
  for( int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < D ; j++){
      cin >> X.at(i).at(j) ; 
    }
  }
  
  for(int i = 0 ; i < N ; i++){
    for(int j = i+1 ; j < N ; j++){
      int norm = 0 ; 
      
      for( int k = 0 ; k < D ; k++){
        int dist = abs( X.at(i).at(k) - X.at(j).at(k) ); 
        norm = norm + dist*dist ; 
      }
      
      for(int k = 0 ; k <= norm ; k++){
        if(k * k  == norm){
          cnt++ ; 
        }
      }
      
    }
  }
  
  cout << cnt << endl ; 
  
}