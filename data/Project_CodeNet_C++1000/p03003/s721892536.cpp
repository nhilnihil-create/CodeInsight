#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> S(N),T(M);
  for(int i=0; i<N; i++){
    cin >> S[i];
  }
  for(int i=0; i<M; i++){
    cin >> T[i];
  }
  vector<vector<ll>> dp(N+1, vector<ll> (M+1,0));
  vector<vector<ll>> sum(N+1, vector<ll> (M+1,0));
  dp[0][0] = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(S[i] == T[j]){
        dp[i+1][j+1] = sum[i][j] + 1;
        dp[i+1][j+1] %= mod;
      }else{
        dp[i+1][j+1] = 0;
      }
      sum[i+1][j+1] = (sum[i][j+1] + sum[i+1][j] + dp[i+1][j+1] + mod - sum[i][j])%mod;
    }
  }
  ll ans = 0;
  for(int i=0; i<=N; i++){
    for(int j=0; j<=M; j++){
      ans += dp[i][j];
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}