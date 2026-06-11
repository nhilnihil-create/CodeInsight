#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0, co = 0;
  char bf;
  rep(i, s.size()){
    if(i == 0){
      bf = s.at(i);
      co++;
      continue;
    }
    if(bf != s.at(i)){
      ans += co-1;
      bf = s.at(i);
      co = 0;
    }
    co++;
  }
  ans += co-1;
  // cerr << ans << endl;
  ans = min(n-1, ans+2*k);
  cout << ans << endl;

  return 0;
}