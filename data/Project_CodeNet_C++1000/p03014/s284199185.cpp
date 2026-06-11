#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i < (int)(n+1); i++)
#define N_MAX 110
#define K_MAX 100010

int main() {
  int H, W;
  
  cin >> H >> W;

  vector<string> S(H);
  vector<vector<int>> dp(H, vector<int> (W));


  rep(i,H){
    cin >> S.at(i);
  }

  rep(i,H){
    vector<int> done(W);
    rep(j,W){
      if(S.at(i).at(j) == '#') continue;
      if(done.at(j) == 1) continue;

      int p = 0;
      while(j+p < W){
        if(S.at(i).at(j+p) == '#') break;
        p++;
      }
      rep(k,p){
        dp.at(i).at(j+k) += p;
        done.at(j+k) = 1;
      }
    }
  }

  rep(j,W){
    vector<int> done(H);
    rep(i,H){
      if(S.at(i).at(j) == '#') continue;
      if(done.at(i) == 1) continue;

      int p = 0;
      while(i+p < H){
        if(S.at(i+p).at(j) == '#') break;
        p++;
      }
      rep(k,p){
        dp.at(i+k).at(j) += p;
        done.at(i+k) = 1;
      }
    }
  }

  int res = 0;
  rep(i,H){
    rep(j,W){
      res = max(res, dp.at(i).at(j)-1);
    }
  }
  cout << res << endl;
  return 0;
}