#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep1(i,n) for(int i=1; i<(int)n; i++)
#define repa(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a / gcd(a, b)*b;}

int N, M, K, H, W, L, R, X;
//string S, T;

signed main(){
  cin >> H >> W;
  vs s(H);
  rep(i,H) cin >> s[i];
  vector<vector<pii>> hw(H,vector<pii>(W,pii(0,0)));

  rep(i,H){
    int cnt = 0;
    vi chk;
    rep(j,W){
      if(s[i][j]=='.'){
        cnt++;
        chk.push_back(j);
      }
      if(s[i][j]=='#' || j== W-1){
        if(cnt == 0) continue;
        rep(k,chk.size()){
          hw[i][chk[k]].second = cnt;
        }
        chk.clear();
        cnt = 0;
      }
    }
  }
  
  rep(i,W){
    int cnt = 0;
    vi chk;
    rep(j,H){
      if(s[j][i]=='.'){
        cnt++;
        chk.push_back(j);
      }
      if(s[j][i]=='#' || j== H-1){
        if(cnt == 0) continue;
        rep(k,chk.size()){
          hw[chk[k]][i].first = cnt;
        }
        chk.clear();
        cnt = 0;
      }
    }
  }
  int ans = 0;
  rep(i,H){
    rep(j,W){
      ans = max(ans, hw[i][j].first + hw[i][j].second);
    }
  }
    
  cout << ans-1 << endl;
  return 0;
}
