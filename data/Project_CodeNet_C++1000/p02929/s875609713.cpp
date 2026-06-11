#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

const int MOD = 1e9 + 7;

//http://hiramekun.hatenablog.com/entry/2019/08/25/043546
signed main(){

  int n; cin >> n;
  string s; cin >> s;

  int left = 0,ans = 1;
  for(int i = 0; i < n*2; i++){
    if(i%2 == 0 && s[i] == 'W' || i%2 == 1 && s[i] == 'B'){
      ans = (ans * left) % MOD;
      left--;
      if(left < 0) break;
    }
    else {
      left++;
    }
  }

  if(left != 0){
    cout << 0 << endl;
    return 0;
  }

  for(int i = 1; i <= n; i++){
    ans = (ans * i) % MOD;
  }
  cout << ans << endl;

  return 0;
}
