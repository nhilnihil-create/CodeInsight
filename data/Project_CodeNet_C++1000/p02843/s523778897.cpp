#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t x;
  cin >> x;
 
  while( (x%100) > 5){
    x = x - 105;
  }
  
  if(99 < x){
    cout << 1 << endl;
  }
  else if(x < 100){
    cout << 0 << endl;
  }    

  
}