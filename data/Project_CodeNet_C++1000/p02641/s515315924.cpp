#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  int ans;
  int min = 1000;
  for(int i=-100; i<=200; i++) {
    bool skip = false;
    for(int j=0; j<n; j++) if(i==v[j]) skip = true;
    if(skip) continue;
      
    if(abs(i-x)<min) {
      min = abs(i-x);
      ans = i;
    }
    
  }
  
  cout << ans << endl;
  return 0;
}