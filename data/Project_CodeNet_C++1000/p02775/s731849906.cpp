#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

int inf = 1000000000;
int dp[1000010][2];

int main() {
  iostream_init();
  string s;
  cin >> s;
  reverse(all(s));
  s += '0';
  int n = len(s);
  rep(i,0,n+1) rep(j,0,2) dp[i][j] = inf;
  dp[0][0] = 0;
  rep(i,0,n) rep(j,0,2) {
    int d = s[i]-'0';
    d += j;
    if (d < 10) dp[i+1][0] = min(dp[i+1][0], dp[i][j]+d);
    if (d > 0) dp[i+1][1] = min(dp[i+1][1], dp[i][j]+10-d);
  }
  int ans = dp[n][0];
  cout << ans << endl;
  return 0;
}
