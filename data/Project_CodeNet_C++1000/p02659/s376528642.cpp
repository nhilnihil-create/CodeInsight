#include<bits/stdc++.h>
using namespace std ;

int main(){
  int64_t A ;
  double B ; 
  cin >> A >> B ; 
  int64_t C = B*100+0.01 ; //切り捨てされないため
  
  
  cout <<  (int64_t)(A * C)/100 << endl ; 
  
  
}