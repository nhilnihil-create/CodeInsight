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
map<int, int> ma;
  
signed main() {
  int n;
  string s;
  cin >> n >> s;
  rep(i,n) ma[s[i]-'0']++;
  int ans = 0;
  rep(i,10){
    rep(j,10) {
      rep(k,10) {
        int now = 0;
        int search = i;
        rep(si,n) {
          if(now==0) {search = i;}
          else if(now==1) {search = j;}
          else {search = k;}
          int sn = s[si]-'0';
          if(now==2&&sn==search) {
            //cout << i<<" "<<j<<" "<<k << endl;
            ans++;
            break;
          }
          if(sn==search)now++;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}