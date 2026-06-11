#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  ll n;
  cin >> n;
  if(n % 2 == 1){
    cout << 0 << endl;
    return 0;
  }
  n /= 2;
  ll ans = 0;
  ll now = 5;
  while(1){
    if(n/now == 0) break;
    ans += n/now;
    now *= 5;
  }
  cout << ans << endl;
  return 0;
}