#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll H, W;
  cin >> H >> W;
  vvc SS(H, vc(W));
  string S;
  rep(i, H){
    cin >> S;

    rep(j, W) SS[i][j] = S[j];
  }

  vvl cross(H, vl(W, 0));
  ll cnt, leng;

  rep(i, H){
    cnt = 0;

    rep(j, W){
      if(SS[i][j] == '#'){
		leng = cnt;

        while(cnt > 0){
          cross[i][j - cnt] += leng;
          cnt--;
        }
      } else cnt++;
    }

    if(cnt > 0){
      leng = cnt;

      while(cnt > 0){
        cross[i][W - cnt] += leng;
        cnt--;
      }
    }
  }

  rep(j, W){
    cnt = 0;

    rep(i, H){
      if(SS[i][j] == '#'){
        leng = cnt;

        while(cnt > 0){
          cross[i - cnt][j] += leng;
          cnt--;
        }
      } else cnt++;
    }

    if(cnt > 0){
      leng = cnt;

      while(cnt > 0){
        cross[H - cnt][j] += leng;
        cnt--;
      }
    }
  }

  ll ans = -1;

  rep(i, H){
    rep(j, W){
      ans = max(ans, cross[i][j]);
    }
  }

  cout << ans - 1 << endl;
  
  return 0;
}
