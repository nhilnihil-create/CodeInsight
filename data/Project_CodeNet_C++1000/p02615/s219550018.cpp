#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  sort(a.rbegin(), a.rend());
  int ans = 0;
  for(int i = 1; i < n; i++){
    ans += a[i / 2];
  }
  cout << ans << endl;
  
  return 0;
}
