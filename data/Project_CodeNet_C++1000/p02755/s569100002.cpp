#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a,b;
  cin >> a >> b;
  
  int i,hantei = 0;
  
  for ( i = 1; i <= 10000; i++){
    if ( int(i * 0.08) == a && int(i * 0.1) == b ){
      hantei = 1;
      break;
    }
  }
  
  if ( hantei == 1 ){
    cout << i << endl;
  }else{
    cout << -1 << endl;
  }
  
}