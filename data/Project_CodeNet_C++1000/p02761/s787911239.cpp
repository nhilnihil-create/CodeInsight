#include<bits/stdc++.h>
using namespace std ; 

int main () {
  int N , M ; 
  cin >> N >> M ; 
  vector<int> s(M) , c(M) ; 
  bool ans = false ; 
  map<int , int> MAP ; 
  
  for(int i = 0 ; i < M ; i++ ){
    cin >> s.at(i) ;
    cin >> c.at(i) ; 
    MAP[s.at(i)] = c.at(i) ; 
    if(s.at(0) == 1 && c.at(0) == 0 && N != 1 ) {
      cout << "-1" << endl ;
      ans = true ; 
      if(ans) return 0 ;   
    }
  }


  for(int i = 0 ; i < M ; i++){
    for(int j = 0 ; j < M ; j++){
        if(s.at(i) == s.at(j) && c.at(i) != c.at(j)) {
          cout << "-1" << endl ;
          return 0 ; 
        }
    }
  }
  
  for(int i =1 ; i <= N ; i++){
    int A = MAP[i] ;
    if(i == 1 && A == 0 && N > 1){
      A = 1 ; 
    }    
    cout << A ;
  }
}