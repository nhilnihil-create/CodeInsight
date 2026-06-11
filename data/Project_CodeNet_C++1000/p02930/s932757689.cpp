#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int n; cin >> n;

  int ans[501][501];
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int bit = 0;
      while((i >> bit & 1) == (j >> bit & 1)){
        bit++;
      }
      ans[i][j] = bit;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      cout << ans[i][j] + 1 << " ";
    }
    cout << "\n";
  }

  return 0;
}
