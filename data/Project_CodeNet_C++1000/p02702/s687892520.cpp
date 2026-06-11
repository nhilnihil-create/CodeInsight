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

const int mod = 2019;

int main(){
  string s;
  cin >> s;
  map<int, int> mp;
  mp[0] = 1;
  reverse(ALL(s));
  int now = 0;
  vector<int> power(s.size());
  int p = 1;
  rep(i, power.size()){
    power.at(i) = p;
    p *= 10;
    p %= mod;
  }
  rep(i, s.size()){
    int add = (s.at(i) - '0') * power.at(i);
    now += add;
    now %= mod;
    mp[now]++;
  }
  ll ans = 0;
  for(auto p : mp){
    ans += (ll)p.second*(p.second-1)/2;
  }
  cout << ans << endl;
  return 0;
}