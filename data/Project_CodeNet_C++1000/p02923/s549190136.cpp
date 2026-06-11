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
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  int mx = 0, co = 1;
  rep2(i, 1, n){
    if(h.at(i-1) < h.at(i)){
      mx = max(mx, co);
      co = 1;
    }else co++;
  }
  mx = max(mx, co);
  cout << mx-1 << endl;
  return 0;
}