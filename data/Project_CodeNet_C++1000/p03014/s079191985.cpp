# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mp make_pair
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int migi[2002][2002];
int hidari[2002][2002];
int ue[2002][2002];
int shita[2002][2002];

int main(){
  int h, w; cin >> h >> w;
  vector<vector<char>> v(h, vector<char> (w));
  rep(i, h)rep(j, w) cin >> v[i][j];

  int ans = 0;

  rep(i, h){
    rep(j, w){
      if(v[i][j]=='#') migi[i][j] = 0;
      else if(j == 0) migi[i][j] = 1;
      else migi[i][j] = migi[i][j-1] + 1;
    }
  }

  rep(i, h){
    rrep(j, w){
      if(v[i][j]=='#') hidari[i][j] = 0;
      else if(j == w-1) hidari[i][j] = 1;
      else hidari[i][j] = hidari[i][j+1] + 1;
    }
  }

  rep(j, w){
    rep(i, h){
      if(v[i][j]=='#') ue[i][j] = 0;
      else if(i == 0) ue[i][j] = 1;
      else ue[i][j] = ue[i-1][j] + 1;
    }
  }

  rep(j, w){
    rrep(i, h){
      if(v[i][j]=='#') shita[i][j] = 0;
      else if(i == h-1) shita[i][j] = 1;
      else shita[i][j] = shita[i+1][j] + 1;
    }
  }

  rep(i, h) {
    rep(j, w){
      if(v[i][j]=='#') continue;
      chmax(ans, ue[i][j] + shita[i][j] + hidari[i][j] + migi[i][j] - 3);
    }
  }

  cout << ans << endl;
}
