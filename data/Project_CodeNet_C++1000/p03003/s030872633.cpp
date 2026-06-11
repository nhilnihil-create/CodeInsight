#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k); i > (n); i--)
#define FORre(i, k, n) for(int i = (k); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;
const int mod = 1000000007;

int dp0[2005][2005];
int dp1[2005][2005];

int main(void){
  int n, m;
  cin >> n >> m;
  vector<int> s(n+1), t(m+1);
  REP(i, n) cin >> s[i];
  REP(i, m) cin >> t[i];
  dp0[0][0] = 1;

  REP(i, n+1) REP(j, m+1){
    dp0[i+1][j] = (dp0[i+1][j] + dp0[i][j]) % mod;
    dp1[i][j] = (dp1[i][j] + dp0[i][j]) % mod;
    dp1[i][j+1] =(dp1[i][j+1] + dp1[i][j]) % mod;
    if(s[i] == t[j])  dp0[i+1][j+1] = (dp0[i+1][j+1] + dp1[i][j]) % mod;
  }
  cout << dp1[n][m] << endl;


  return 0;
}