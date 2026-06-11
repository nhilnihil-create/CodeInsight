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
  int n,k,s;
  cin >> n >> k >> s;
  int a = 1e9;
  if(s==1e9) a = 1;

  rep(i,n) {
    if(i<k) cout << s <<" "<< flush;
    else cout << a << " "<< flush;
  }
  cout << "" << endl;


  return 0;
}
