#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
constexpr long long mod1 = 1e9+7;
using namespace std;

int main(){
  long long n, k, ans = 0; cin >> n >> k;
  vector<long long> v(k+1, 1);
  rrep(i, k){
    rep(j, k/(i+1)){
      if(j == 0){
        long long u = n, w = k/(i+1);
        while(u > 0){
          if(u & 1){
            v[i+1] *= w;
            v[i+1] %= mod1;
          }
          u /= 2;
          w *= w;
          w %= mod1;
        }
      }
      else{
        v[i+1] += mod1;
        v[i+1] -= v[(i+1)*(j+1)];
        v[i+1] %= mod1;
      }
    }
  }
  rep(i, k){
    ans += v[i+1] * (i+1);
    ans %= mod1;
  }
  cout << ans << "\n";
  return 0;
}