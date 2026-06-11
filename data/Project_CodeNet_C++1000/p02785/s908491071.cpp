#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int64_t n,k;
  cin >> n >> k;
  
  int64_t h[n];
  rep(i,n) cin >> h[i];
  
  sort(h,h+n,greater<int>());
  int64_t ans = 0;
  for(int64_t i = k; i < n; i++){
    ans += h[i];
  }
  
  cout << ans << endl;
    
}