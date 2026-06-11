#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

template <typename T1, typename T2> 
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

struct Sum{
  ll u = 0;
  ll d = 0;
  ll l = 0;
  ll r = 0;
};

ll calc(Sum p) { return p.u + p.d + p.l + p.r; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  string board[h];
  rep(i, h) { cin >> board[i]; }

  struct Sum point[h][w];

  // l -> r
  rep(i,h){
    ll cnt = 0;
    rep(j, w) {
      point[i][j].l = cnt;
      if(board[i][j] == '.') {
        cnt++;
      }else{
        cnt = 0;
      }
    }
  }

  // r -> l
  rep(i, h) {
    ll cnt = 0;
    for(int j = w - 1; j >= 0; j--) {
      point[i][j].r = cnt;
      if(board[i][j] == '.') {
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }

  // u -> d
  rep(j, w) {
    ll cnt = 0;
    rep(i, h) {
      point[i][j].u = cnt;
      if(board[i][j] == '.') {
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }

  // d -> u
  rep(j, w) {
    ll cnt = 0;
    for(int i = h - 1; i >= 0; i--) {
      point[i][j].d = cnt;
      if(board[i][j] == '.') {
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }

  ll ans = 0;
  rep(i, h)rep(j, w) {
    if(board[i][j] == '#') continue;
    chmax(ans, calc(point[i][j]) + 1);
  }

    cout << ans << endl;
    return 0;
}
