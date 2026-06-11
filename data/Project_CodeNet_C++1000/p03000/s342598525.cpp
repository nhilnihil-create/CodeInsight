#include<bits/stdc++.h>
using namespace std;

int main(){
  int N , X ; 
  cin >> N >> X ; 
  vector<int> L(N) ;
  
  for(int i = 0 ; i < N ; i++  ){
    cin >> L.at(i) ; 
    
  }
  
  int cnt =1; 

  for(int i = 0 ; i<N ; i++){
    X = X - L.at(i) ; 
    if( X < 0){
      break ; 
    }
    else {
    cnt++;
    }
  }
  
  cout << cnt << endl ;
}