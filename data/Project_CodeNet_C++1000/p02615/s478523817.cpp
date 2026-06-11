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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(ALL(a), greater<int>());
  ll ans = 0;
  if(n % 2 == 0){
    ans += a.front();
    rep2(i, 1, n/2){
      ans += 2*a.at(i);
    }
  }else{
    ans += a.front();
    rep2(i, 1, n/2){
      ans += 2*a.at(i);
    }
    ans += a.at(n/2);
  }
  cout << ans << endl;
  return 0;
}