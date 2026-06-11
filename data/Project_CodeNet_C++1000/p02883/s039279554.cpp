#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n),f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];

  sort(a.rbegin(),a.rend());
  sort(f.begin(),f.end());
  ll l = -1LL, r = 1e12;
  while(l+1<r){
    ll x = (l+r)/2;
    bool ok = [&](){
      ll nk = k;
      rep(i,n){
        ll t = a[i]*f[i]-x;
        if(t<=0) continue;

        nk -= (t+f[i]-1)/f[i];
        if(nk<0){
          return false;
        }
      }
      return true;
    }();
    if(ok){
      r = x;
    }else{
      l = x;
    }
  }
  cout << r << endl;
}
