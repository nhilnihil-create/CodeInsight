#include <bits/stdc++.h>
using namespace std ;

#define int long long

signed main(){
  int a , b , n ;
  cin >> a >> b >> n ;
  if(n >= b){
    cout << a*(b-1)/b ;
  } else {
    cout << a*n/b ;
  }
  return 0 ; 
}