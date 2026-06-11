#include <bits/stdc++.h>
using namespace std;

int main() {

  int x;
  cin >> x;
  
  int a,frag;
  
  while(true){
    a = 2;
    frag = 1;
    
    while(a * a <= x){
      if ( x % a == 0 ){
        frag = 0;
        break;
      }else{
        a++;
      }
    }
    if ( frag == 0 ){
      x++;
    }else{
      break;
    }
  } 
  
  cout << x << endl;
 
}
