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
  int n;
  cin >> n;
  double a;
  double ans=0;
  rep(i, n) {
    cin >> a;
    ans += 1.0/a;
  }
  cout << setprecision(20)<< 1.0/ans << endl;

  return 0;
}
