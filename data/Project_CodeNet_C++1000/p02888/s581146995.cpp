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
  vector<int> l(n);
  rep(i, n) cin >> l.at(i);
  sort(ALL(l));
  ll ans = 0;
  rep(i, n)rep2(j, i+1, n){
    int il = l.at(i), jl = l.at(j);
    int add = lower_bound(ALL(l), il+jl) - l.begin();
    // cerr << i << " " << j << " " << il+jl << " " << add << endl;
    add = max(0, add-j-1);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}