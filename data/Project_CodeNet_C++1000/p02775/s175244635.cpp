#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define EPS (1e-9)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

const string YES = "";
const string NO  = "";

typedef long long ll;

#define MAX 1000100
string s;
int dp[MAX][2];

void solve() {
  reverse(ALL(s));
  s = s + "0";
  int n = s.size();
  rep(i,n+1) rep(j,2) dp[i][j] = INT_MAX;
  dp[0][0] = 0;
  rep(i,n) {
    int v = s[i] - '0';
    rep(j,2) {
      if( dp[i][j] == INT_MAX ) continue;
      int next_bit = 0;
      int val = v + j;
      if( val >= 10 ) {
	val -= 10;
	next_bit = 1;
      }
      // just pay
      if( dp[i+1][next_bit] > dp[i][j] + val ) {
	dp[i+1][next_bit] = dp[i][j] + val;
      }
      // pay + 1
      if( dp[i+1][1] > dp[i][j] + ( 10 - val ) ) {
	dp[i+1][1] = dp[i][j] + ( 10 - val );
      }
    }
  }
  int mini = INT_MAX;
  rep(i,2) mini = min(mini,dp[n][i]);
  cout << mini << endl;
}

int main() {
  cin >> s;
  solve();
  return 0;
}
