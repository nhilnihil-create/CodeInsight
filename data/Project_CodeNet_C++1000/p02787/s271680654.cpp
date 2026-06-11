#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,n; cin >> h >> n;
  vi a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  const int INF = 1001001001;
  vector<vi> dp(n+1,vi(h+1,INF));
  dp[0][0] = 0;
  rep(i,n) rep(j,h+1){
    chmin(dp[i+1][j],dp[i][j]);
    int next_j = min(h,j+a[i]);
    chmin(dp[i+1][next_j],dp[i+1][j]+b[i]);
  }
  cout << dp[n][h];
  cout << "\n";
  return 0;
}
