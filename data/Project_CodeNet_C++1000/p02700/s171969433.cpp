#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  while(1){
    
    if(c - b <= 0){
      cout << "Yes" << endl;
      break;
    }
    else{
      c = c - b;
      if(a - d <= 0){
        
        cout << "No" << endl;
        break;

      }
      else{
        a = a - d;
      }
      
    }
    
  }
  
  
}

