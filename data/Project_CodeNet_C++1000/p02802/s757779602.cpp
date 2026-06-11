#include<bits/stdc++.h>
using namespace std ; 


int main() {
  int N , M ; 
  cin >> N >> M ; 
  int p ;
  string S ; 
  vector<int> ac(N) , pena(N) ; 
  int AC= 0  , WA=0 ;  
  
  for(int i = 0 ; i < M ; i++){
    cin >> p >> S ; 
    
    if(S == "AC"){
      ac.at(p-1) = 1 ; 
    }
    else if(S == "WA" && ac.at(p-1) != 1 ){
      pena.at(p-1)++ ;     
      //cout << pena.at(p-1) << endl ; 
      
    }
  }
    
   
  
  for(int i = 0 ; i < N ; i++){
    AC  += ac.at(i) ;
    if(ac.at(i)) WA += pena.at(i) ; 
  }
  
  cout << AC << " " << WA << endl ; 
}