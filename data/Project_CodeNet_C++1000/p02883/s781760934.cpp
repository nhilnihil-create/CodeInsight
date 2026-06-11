#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long


signed main() {
  int n, k;
  cin >> n>>k;
  vector<int> a(n);
  vector<int> f(n);  
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> f[i];
  sort(a.begin(), a.end(),greater<int>());
  sort(f.begin(), f.end());
  int l = -1, r =1e12;
  while(l+1<r) {
    int mid = (l+r)/2;
    bool ok = [&]{
      ll s = 0;
      rep(i,n) s+=max(0ll,a[i]-mid/f[i]);
      return s<=k;
    }();
    if(ok) r = mid;
    else l = mid; 
  }
  cout << r << endl;
  return 0;
}