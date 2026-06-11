#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
constexpr ll INF=1LL<<60;
const ll dx[]={1,0};
const ll dy[]={0,1};
int main()
{
  ll h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(auto&& e: s) 
  {
    cin>>e;
  }
  vector<vector<ll>> dp(h,vector<ll>(w,INF));
  dp[0][0]=s[0][0]=='#'?1:0;

  queue<pair<ll,ll>> nxt;
  nxt.push({0,0});
  while (!nxt.empty()) {
    ll x=nxt.front().first;
    ll y=nxt.front().second;
    nxt.pop();
    for (int i = 0; i < 2; ++i) {
      ll nx=x+dx[i];
      ll ny=y+dy[i];
      if (nx>=h||ny>=w) continue;
      if (dp[nx][ny]>dp[x][y]+((s[x][y]=='.'&&s[nx][ny]=='#')? 1:0)) {
        dp[nx][ny]=dp[x][y]+((s[x][y]=='.'&&s[nx][ny]=='#')? 1:0);
        nxt.push({nx,ny});
      }
    }
  }
  // for (int i = 0; i < h; ++i)
  // {
  //   for (int j = 0; j < w; ++j)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout<<dp[h-1][w-1]<<endl;
}