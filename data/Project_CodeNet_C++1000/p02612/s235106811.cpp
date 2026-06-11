#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  int ans = 10000;
  int t = 0;
  
  for (int i = 0; i <= 10; i++){
    int x = 1000 * i;
    if(n == x){
      cout << 0 << endl;
      t = 1;
      break;
    }
    else if(n - x < 0){
      int y = (n - x) * -1;
      if (y < ans){
        ans = y;
      }
    }
    
  }
  
  
  
  if(t == 0){
    cout << ans <<endl;
  }
  
  

}



