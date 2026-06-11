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
  int k;
  cin >> k;
  ll sum = 0;
  rep2(i, 1, k+1){
    rep2(j, 1, k+1){
      int g = __gcd(i, j);
      rep2(l, 1, k+1){
        sum += __gcd(g, l);
      }
    }
  }
  cout << sum << endl;
  return 0;
}