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
  ll H,W; cin>>H>>W;
  vector<string> grid(H); rep(i,H) cin>>grid[i];
  
  //列ごと行ごとに障害物のある位置をメモ
  vector<vector<ll>> gyo(H,vector<ll>(0));
  vector<vector<ll>> retsu(W,vector<ll>(0));
  
  rep(y,H){
    rep(x,W){
      if(grid[y][x]=='#') {
        gyo.at(y).push_back(x);
        retsu.at(x).push_back(y);
      }
    }
  }
  
  //全探索
  ll ans=0;
  rep(y,H){
    rep(x,W){
      if(grid[y][x]=='#') continue;
      ll sans=0;
      
      //行の探索
      //左端の探索
      ll ok=-1,ng=gyo.at(y).size();
      while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(gyo[y][mid]<x) ok=mid;
        else ng=mid;
      }
      ll left;
      if(ok==-1) left=0;
      else left=gyo[y][ok]+1;
      
      //右端の探索
      ok=gyo.at(y).size(),ng=-1;
      while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(gyo[y][mid]>x) ok=mid;
        else ng=mid;
      }
      ll right;
      if(ok==gyo.at(y).size()) right=W;
      else right=gyo[y][ok];
      
      //列の探索
      //上端の探索
      ok=-1,ng=retsu[x].size();
      while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(retsu[x][mid]<y) ok=mid;
        else ng=mid;
      }
      ll up;
      if(ok==-1) up=0;
      else up=retsu[x][ok]+1;
      
      //下端の探索
      ok=retsu[x].size(),ng=-1;
      while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(retsu[x][mid]>y) ok=mid;
        else ng=mid;
      }
      ll bottom;
      if(ok==retsu[x].size()) bottom=H;
      else bottom=retsu[x][ok];
      
      sans=right-left+bottom-up-1;
      chmax(ans,sans);
    }
  }
  
  cout<<ans<<endl;  
      
  return 0;
}