#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

const int MOD = 1000000007;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = 1;
  vector<int> h(n, 0);
  h[0] = 3;
  for(int i = 0; i < n; i++){
    ans = (ans * h[a[i]]) % MOD;
    h[a[i]]--;
    h[a[i]+1]++;
  }
  cout << ans << endl;

  return 0;
}