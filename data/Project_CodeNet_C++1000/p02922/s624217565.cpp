#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int A , B ; 
  cin >> A >> B ; 
  int outlet = 1; 
  int cnt = 0 ; 

  while( B > outlet  ){
	outlet-- ;
    outlet += A ; 
    cnt++ ; 
  }

  cout << cnt << endl ;
}