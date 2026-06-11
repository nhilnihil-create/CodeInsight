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
  string s;
  cin >> s;
  int n = s.size();
  string rs = s;
  reverse(rs.begin(), rs.end());
  string fr = s.substr(0, (n-1)/2);
  string rfr = fr;
  reverse(rfr.begin(), rfr.end());
  string re = s.substr((n+3)/2-1);
  string rre = re;
  reverse(rre.begin(), rre.end());
  cerr << fr << " " << re << endl;
  if(s ==rs && fr == rfr && re == rre) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}