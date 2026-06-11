#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fc(vector<tuple<ll, int, int>> &vt, ll k, ll m){
  int n = vt.size();
  rep(i, n){
    ll t;
    int a, f;
    tie(t, a, f) = vt.at(i);
    if(t <= m) continue;
    int ad = m/f;
    int d = a - ad;
    k -= d;
    if(k < 0) return false;
  }
  return true;
}

int main(){
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  vector<int> f(n);
  rep(snip_i, n) cin >> f.at(snip_i);
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  vector<tuple<ll, int, int>> vt(n);
  rep(i, n){
    vt.at(i) = make_tuple((ll)a.at(i)*f.at(i), a.at(i), f.at(i));
  }
  ll ng = -1, ok = 1e18+5;
  while(ok-ng>1){
    ll mid = (ok+ng)/2;
    if(fc(vt, k, mid) == true) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}