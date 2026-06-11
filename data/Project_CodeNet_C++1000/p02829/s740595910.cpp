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
int dp[100100];
int cnt = 0;
signed main() {
  int a,b;
  cin >> a>> b;
  if(a>b)swap(a,b);
  if(a==1&&b==2)cout << 3 << endl;
    if(a==1&&b==3)cout << 2 << endl;
      if(a==2&&b==3)cout << 1 << endl;



  return 0;
}