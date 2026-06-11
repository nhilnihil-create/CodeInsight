#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w; cin >> h >> w;
  vector<string> s(h); rep(i,h) cin >> s[i];
  vector<vi> dp(h,vi(w,INF));
  dp[0][0] = (s[0][0] == '#');
  rep(i,h){
    rep(j,w){
      if(0 <= j-1){
        if(s[i][j-1] != s[i][j]) chmin(dp[i][j],dp[i][j-1]+1);
        else chmin(dp[i][j],dp[i][j-1]);
      }
      if(0 <= i-1){
        if(s[i-1][j] != s[i][j]) chmin(dp[i][j],dp[i-1][j]+1);
        else chmin(dp[i][j],dp[i-1][j]);
      }
    }
  }
  if(s[h-1][w-1] == '#') dp[h-1][w-1]++;
  cout << dp[h-1][w-1]/2;
  cout << "\n";
  return 0;
}
