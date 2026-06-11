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
  vector<int> ans(n);
  ll sum = 0;
  rep(i, n) sum += a.at(i);
  ll mi = 0;
  for(int i = 1; i < n; i += 2){
    mi += a.at(i);
  }
  ans.at(0) = sum - 2 * mi;
  rep(i, n-1) ans.at(i+1) = 2 * a.at(i) - ans.at(i);
  rep(i, n){
    if(i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}