#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int ans;
  if(n==2) ans = 2; 
  
  else {
    if(n%2==0) n++;
    for(int i=n; ; i+=2) {
      
      if(i%2==0) continue;
    
      bool prime = true;
      double x = sqrt(i);
      for (int j=3; j<=x; j+=2) {
        if(i%j==0) {
          prime = false;
          break;
        }
      }
    
      if(prime) {
        ans = i;
        break;
      }
    
    }
  }
  
  cout << ans << endl;
  return 0;
}