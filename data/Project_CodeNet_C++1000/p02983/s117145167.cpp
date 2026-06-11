#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t L, R; cin >> L >> R; int ans = 2020;
  
  if (2020LL < R - L) { cout << 0 << endl; return 0; }
  
  for (int64_t i = L; i < R; i++) {
    
    for (int64_t j = i + 1; j < R + 1; j++) {
      
      int64_t left = i % 2019, right = j % 2019;
      
      int tmp = left * right % 2019;
      
      ans = min(ans, tmp);
      
    }
    
  }
  
  cout << ans << endl;
  
}