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
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  vector<bool> chk(n, false);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(h.at(a) <= h.at(b)) chk.at(a) = true;
    if(h.at(b) <= h.at(a)) chk.at(b) = true;
  }
  int ans = 0;
  rep(i, n){
    if(chk.at(i) == false) ans++;
  }
  cout << ans << endl;
  return 0;
}