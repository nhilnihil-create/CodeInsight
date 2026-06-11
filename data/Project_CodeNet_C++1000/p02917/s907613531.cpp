#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> b(n-1);
  rep(i, n-1){
    int in;
    cin >> in;
    b.at(i) = in;
  }
  int ans = 0;
  rep(i, n){
    if(i == 0) ans += b.at(0);
    else if(i == n-1) ans += b.back();
    else ans += min(b.at(i-1), b.at(i));
  }
  cout << ans << endl;
  return 0;
}