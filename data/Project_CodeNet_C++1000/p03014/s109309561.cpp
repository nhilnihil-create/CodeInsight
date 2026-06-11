#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
ll dpD[2010][2010],dpU[2010][2010],dpL[2010][2010],dpR[2010][2010];
int main(){
  int h,w;
  cin >> h >> w;
  vector<string>v(h);
  rep(i,h)cin >> v[i];
  for(int i = 1; i < h; i++){
    rep(j,w){
      if(v[i][j] == '#')continue;
      if(v[i - 1][j] == '#')dpD[i][j] = 0;
      else dpD[i][j] += dpD[i - 1][j] + 1;
    }
  }
  for(int i = h - 2; i >= 0; i--){
    rep(j,w){
      if(v[i][j] == '#')continue;
      if(v[i + 1][j] == '#')dpU[i][j] = 0;
      else dpU[i][j] += dpU[i + 1][j] + 1;
    }
  }
  rep(i,h){
    for(int j = 1; j < w; j++){
      if(v[i][j] == '#')continue;
      if(v[i][j - 1] == '#')dpL[i][j] = 0;
      else dpL[i][j] += dpL[i][j - 1] + 1;
    }
  }
  rep(i,h){
    for(int j = w - 2; j >= 0; j--){
      if(v[i][j] == '#')continue;
      if(v[i][j + 1] == '#')dpR[i][j] = 0;
      else dpR[i][j] += dpR[i][j + 1] + 1;
    }
  }
  ll ans = 0;
  rep(i,h)rep(j,w){
    ans = max(ans,dpR[i][j] + dpL[i][j] + dpU[i][j] + dpD[i][j]);
  }
  cout << ans + 1 << endl;
  return 0;
}
