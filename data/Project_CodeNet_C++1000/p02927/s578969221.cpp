#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, d;
  cin >> m >> d;
  
  int ans = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= d; j++){
      int k = j, mul = 1;
      bool ok = false;
      if(j < 22) continue;
      while(k > 0){
        int t = k % 10;
        if(t < 2) ok = true;
        mul *= t;
        k /= 10;
      }
      if(ok) continue;
      if(mul == i) ans++;
    }
  }
  
  cout << ans << endl;
}