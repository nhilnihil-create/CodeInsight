#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll H,W,A,B; cin>>H>>W>>A>>B;
  string str=""; rep(i,W) str+='.';
  vector<string> grid(H,str);
  
  rep(i,H){
    rep(j,W){
      if(i<B&&j<A) grid[i][j]='0';
      else if(i>=B&&j>=A) grid[i][j]='0';
      else grid[i][j]='1';
    }
  }
  
  for(auto s:grid) cout<<s<<endl;
  return 0;
}