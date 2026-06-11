#include<bits/stdc++.h>
using namespace std;

int main() {
  int h,w,k;
  cin >> h >> w >> k;
  
  vector<string> s(h);
  
  for (int i = 0; i < h; i++) cin >> s.at(i);
  
  int ans = 0;
  
  for (int bh = 0; bh < (1 << h); bh++) {
    for (int bw = 0; bw < (1 << w); bw++) {
      
      int count = 0;
      
      for (int i = 0; i < h; i++) {
        
        if (bh >> i & 1) continue;
        
        for (int j = 0; j < w; j++) {
          if (bw >> j & 1) continue;
          if (s.at(i).at(j) == '#') count++;
        }
        
      }
      if (count == k) ans++;
    }
    
  }
  cout << ans << endl;
}