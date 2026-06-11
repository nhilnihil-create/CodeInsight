#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int x, h, cnt = 0, ans = 0;
  for(int i=0; i<n; i++) {
    cin >> h;
    if(i==0) {
      x = h;
      continue;
    }
    
    else if(h <= x) cnt++;
    else if(h > x) {
      ans = max(ans, cnt);
      cnt = 0;
    }
    if(i==n-1) ans = max(ans, cnt);
    x = h;
  } 
  
  cout << ans << endl;
  return 0;
}