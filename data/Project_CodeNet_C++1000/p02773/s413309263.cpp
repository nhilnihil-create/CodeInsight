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
map<string,int> ma;
signed main() {
  int n;
  cin >> n;
  int ans = 0;
  rep(i,n) {
    string str;
    cin >> str;
    ma[str]++;
  }
  int mm = 0;
  for(auto m: ma) {
    mm = max(m.second,mm);
  }
  vector<string> str;
  for(auto m: ma) {
    if(mm==m.second) {
      str.push_back(m.first);
    }
  }
  sort(str.begin(),str.end());
  for(auto m: str) cout << m << endl;

  return 0;
}