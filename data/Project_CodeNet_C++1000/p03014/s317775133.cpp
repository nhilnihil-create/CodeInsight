#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H);
  vector<vector<int>> up(H, vector<int>(W)), down(H, vector<int>(W)), left(H, vector<int>(W)), right(H, vector<int>(W));

  rep(i, 0, H){
    rep(k, 0, W){
      char c; cin >> c;
      vec[i].push_back(c);
    }
  }

  rep(k, 0, W){
    int nup = 0;
    rep(i, 0, H - 1){
      if(vec[i][k] == '#') nup = 0;
      else ++nup;
      if(vec[i + 1][k] == '#') up[i + 1][k] = 0;
      else up[i + 1][k] = nup;
    }
  }

  rep(k, 0, W){
    int ndown = 0;
    for(int i = H - 1; i > 0 ; --i){
      if(vec[i][k] == '#') ndown = 0;
      else ++ndown;
      if(vec[i - 1][k] == '#') down[i - 1][k] = 0;
      else down[i - 1][k] = ndown;
    }
  }

  rep(i, 0, H){
    int nleft = 0;
    rep(k, 0, W - 1){
      if(vec[i][k] == '#') nleft = 0;
      else ++nleft;
      if(vec[i][k + 1] == '#') left[i][k + 1] = 0;
      else left[i][k + 1] = nleft;
    }
  }

  rep(i, 0, H){
    int nright = 0;
    for(int k = W - 1; k > 0; k--){
      if(vec[i][k] == '#') nright = 0;
      else ++nright;
      if(vec[i][k - 1] == '#') right[i][k - 1] = 0;
      else right[i][k - 1] = nright;
    }
  }


  int maxi = 0;
  rep(i, 0, H){
    rep(k, 0, W){
      if(vec[i][k] == '#') continue;
      int comp = 1 + up[i][k] + down[i][k] + left[i][k] + right[i][k];
      if(maxi < comp) maxi = comp;
    }
  }

  cout << maxi << endl;

}