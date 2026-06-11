#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int n; cin >> n;

  int ans[501][501];
  function< void(int,int,int) > rec =
  [&](int left,int right,int level){
    if(right - left <= 1) return;
    int mid = (left + right) / 2;
    for(int i = left; i < mid; i++){
      for(int j = mid; j < right; j++){
        ans[i][j] = level;
      }
    }
    rec(left,mid,level+1);
    rec(mid,right,level+1);
  };
  rec(0,n,1);

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
