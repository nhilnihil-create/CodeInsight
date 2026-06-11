#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main() {
  // input
  long h,w; cin >> h >> w;
  
  // compute
  long c1,ans;
  c1 = (h / 2) + (h % 2);
  ans = (w / 2) * h + (w % 2) * c1 ;
  
   if(h == 1 || w == 1){
    ans = 1;
  }
 
  // output  

  cout << ans << endl;
  
}