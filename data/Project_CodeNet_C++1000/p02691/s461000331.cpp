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
  map<int, ll> mp;
  vector<int> a(n);
  rep(i, n){
    int in;
    cin >> in;
    a.at(i) = in;
    mp[(i+1)+in]++;
  }
  ll ans = 0;
  rep(i, n){
    int l = (i+1) - a.at(i);
    ans += mp[l];
  }
  cout << ans << endl;
  return 0;
}