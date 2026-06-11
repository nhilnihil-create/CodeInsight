#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long h, w;
  cin >> h >> w;
  
  bool heven = h%2==0;
  bool weven = w%2==0;
  long long ans;
  
  if (h!=1 && w!=1 ) {
    
    if (heven && weven)
      ans = h * w / 2;
    else if (!heven && weven)
      ans = w / 2 * h;
    else if (heven && !weven)
      ans = h / 2 * w;
    else
     ans = h / 2 * w + w / 2 + 1;
    
  }
  
  else
    ans = 1;
      
  cout << ans << endl;
}