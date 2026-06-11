#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

const int INF = 1001001001;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  vector<vector<int>> dp(h, vector<int>(w, INF));
  if(s.at(0).at(0) == '.') dp.at(0).at(0) = 0;
  else dp.at(0).at(0) = 1;
  rep(i, h){
    rep(j, w){
      int di[] = {1, 0}, dj[] = {0, 1};
      rep(k, 2){
        int ni = i + di[k], nj = j + dj[k];
        if(nj < 0 || w <= nj || ni < 0 || h <= ni) continue;
        int add = 0;
        if(s.at(i).at(j) == '.' && s.at(ni).at(nj) == '#')add++;
        dp.at(ni).at(nj) = min(dp.at(ni).at(nj), dp.at(i).at(j) + add);
      }
    }
  }
  cout << dp.at(h-1).at(w-1) << endl;
  return 0;
}