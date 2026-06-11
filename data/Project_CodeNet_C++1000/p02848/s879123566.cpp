#include<bits/stdc++.h>
using namespace std ; 

int main() {

  int N ;
  string S ; 
  cin >> N ; 
  cin >> S ; 
  int T = S.size() ; 


  
  for( int i = 0 ; i < T ; i++  ){
    char A = S.at(i) ; 
    int X =  A - 'A' ; 
    X = (N+X)%26 ; 
    
    cout <<(char)('A' + X ) ; //int からcharへ
  }
 
}

