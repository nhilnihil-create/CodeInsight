#include<bits/stdc++.h>
using namespace std ; 

int main() {
  long long P , X ;
  cin >> X ; 
  int Y=0 ; 
  P=100 ; 
  
  while (P < X){
    P += P/100 ; 
    Y++ ; 
  }
  
  
  cout << Y << endl ; 
  
  
  
}
