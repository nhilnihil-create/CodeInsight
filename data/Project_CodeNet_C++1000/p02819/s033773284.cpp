#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, ans;
  cin >> X;
  ans = X;
  bool sosu = true;
  if(ans ==2 || ans ==3 || ans ==5 || ans ==7){
    sosu = false;
  }
  
  while(sosu){
      for(int i = 2; i<ans; i++){
        if(ans%i==0){
          ans ++; break;
        }
        
        if(i*i>ans){
          sosu = false;
          break;
        }
      }
  }
  
  cout << ans << endl;
}