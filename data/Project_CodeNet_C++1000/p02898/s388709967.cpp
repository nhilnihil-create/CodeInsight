#include<bits/stdc++.h>
using namespace std ; 


int main(){
  int N , K , cnt; 
  cin >> N >> K ; 
  vector<int> h(N) ; 
  cnt = 0 ; 
  
  for (int i = 0 ; i < N ; i++){
    cin >> h[i] ;
    if(h[i] >= K){
      cnt++ ; 
    }
  }
  
  cout << cnt << endl ; 
  
  
}
