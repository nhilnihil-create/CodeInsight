#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s[i];
  vector<vector<ll>> L(h, vector<ll>(w)), R(h, vector<ll>(w)), D(h, vector<ll>(w)), U(h, vector<ll>(w));
  
  REP(i, h){
    REP(j, w){
      if(s[i][j] == '#') L[i][j] = 0;
      else if(j == 0) L[i][j] = 1;
      else L[i][j] = L[i][j-1] + 1;

      if(s[i][w-1-j] == '#') R[i][w-1-j] = 0;
      else if(j == 0) R[i][w-1-j] = 1;
      else R[i][w-1-j] = R[i][w-j] + 1;
    }
  }

  REP(j, w){
    REP(i, h){
      if(s[i][j] == '#') U[i][j] = 0;
      else if(i == 0) U[i][j] = 1;
      else U[i][j] = U[i-1][j] + 1;

      if(s[h-1-i][j] == '#') D[h-1-i][j] = 0;
      else if(i == 0) D[h-1-i][j] = 1;
      else D[h-1-i][j] = D[h-i][j] + 1;
    }
  }

  ll ans = 0;
  REP(i, h) REP(j, w){
    chmax(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
  }
  cout << ans << endl;
  return 0;
}