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
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  vector<int> s = p;
  sort(s.begin(), s.end());
  int co = 0;
  rep(i, n){
    if(s.at(i) != p.at(i)) co++;
  }
  if(co <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}