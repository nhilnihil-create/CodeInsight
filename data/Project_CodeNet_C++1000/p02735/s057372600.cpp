#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<string> grid;
ll H,W;

bool movable(ll sh,ll sw)
{
  if(sh<0||sh>=H||sw<0||sw>=W) return false;
  return true;
}  

vector<vector<ll>> table;
ll dp(ll h,ll w)
{
  if(table.at(h).at(w)<INF) return table.at(h).at(w);
  table.at(h).at(w)-=1;
  //右移動
  if(movable(h,w-1))
  {
    if(grid.at(h).at(w-1)=='.'&&grid.at(h).at(w)=='#') chmin(table.at(h).at(w),dp(h,w-1)+1);
    else chmin(table.at(h).at(w),dp(h,w-1));
  }
  //下移動
  if(movable(h-1,w))
  {
    if(grid.at(h-1).at(w)=='.'&&grid.at(h).at(w)=='#') chmin(table.at(h).at(w),dp(h-1,w)+1);
    else chmin(table.at(h).at(w),dp(h-1,w));
  }
  return table.at(h).at(w);
}  
int main() 
{
  cin>>H>>W;
  grid=vector<string>(H);
  rep(i,H)
  {
    cin>>grid.at(i);
  }
  table=vector<vector<ll>>(H,vector<ll>(W,INF));
  if(grid.at(0).at(0)=='.') table.at(0).at(0)=0;
  else table.at(0).at(0)=1;
  cout<<dp(H-1,W-1)<<endl;
  return 0;
}
