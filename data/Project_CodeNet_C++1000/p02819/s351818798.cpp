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

set<int> make_prime_set(int lim){
  set<int> ps;
  vector<bool> chk(lim+1, true);
  chk.at(0) = chk.at(1) = false;
  rep2(i, 2, chk.size()){
    if(chk.at(i) == false) continue;
    ps.insert(i);
    for(int j = i+i; j < chk.size(); j +=i) chk.at(j) = false;
  }
  return ps;
}

int main(){
  auto ps = make_prime_set(1e6);
  int a;
  cin >> a;
  cout << *ps.lower_bound(a) << endl;
  return 0;
}